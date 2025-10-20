/**************************************************************
 * ESP32-S3 DevKit (N16R8) + Arduino IDE 2.3.6
 * Blynk + LEDs + 2x VR + MLX90614 (I2C)
 * - V0/V1/V2 : Switch -> GPIO 2/4/5 (LEDs)
 * - V3       : VR1 (GPIO 6)  analogRead 0..4095
 * - V4       : VR2 (GPIO 7)  analogRead 0..4095
 * - V5       : MLX90614 Ambient °C
 * - V6       : MLX90614 Object  °C
 **************************************************************/

#define BLYNK_TEMPLATE_ID   "TMPL6t6VT75Ra-"
#define BLYNK_TEMPLATE_NAME "ESP32S3"
#define BLYNK_AUTH_TOKEN    "116xqFNbNe-1XPtxi9RQ--MON_fBuBGI"

#define BLYNK_PRINT Serial

// ---------- WiFi ----------
char ssid[] = "CEGuest";   // หากเป็น captive-portal จะต่อ Blynk ไม่ได้ -> แนะนำ Hotspot/เครือข่ายปกติ
char pass[] = "";

// ---------- LEDs ----------
#define LED0_PIN 2
#define LED1_PIN 4
#define LED2_PIN 5

#ifndef LED_ACTIVE_LOW
#define LED_ACTIVE_LOW 0
#endif

// ---------- VR analog pins (ESP32-S3 ADC1) ----------
#define VR1_PIN 6   // 0..4095
#define VR2_PIN 7   // 0..4095

// ---------- I2C pins for MLX90614 ----------
#define I2C_SDA 8
#define I2C_SCL 9
#define I2C_FREQ 100000UL  // 100 kHz

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

BlynkTimer timer;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// ---------------- Helpers ----------------
inline void setLed(uint8_t pin, bool on) {
#if LED_ACTIVE_LOW
  digitalWrite(pin, on ? LOW : HIGH);
#else
  digitalWrite(pin, on ? HIGH : LOW);
#endif
}

// ---------------- Blynk Handlers ----------------
BLYNK_WRITE(V0) { setLed(LED0_PIN, param.asInt()); }
BLYNK_WRITE(V1) { setLed(LED1_PIN, param.asInt()); }
BLYNK_WRITE(V2) { setLed(LED2_PIN, param.asInt()); }

BLYNK_CONNECTED() {
  // sync สถานะสวิตช์ LED เมื่อออนไลน์
  Blynk.syncVirtual(V0, V1, V2);
}

// ----------- Periodic Tasks -----------
void taskSendVR() {
  int vr1 = analogRead(VR1_PIN);
  int vr2 = analogRead(VR2_PIN);
  Blynk.virtualWrite(V3, vr1);
  Blynk.virtualWrite(V4, vr2);
  Serial.printf("VR1(GPIO %d)=%d  VR2(GPIO %d)=%d\n", VR1_PIN, vr1, VR2_PIN, vr2);
}

void taskSendMLX() {
  static bool mlx_ok = true;
  if (!mlx_ok) return; // หาก init fail จะไม่อ่านซ้ำทุกครั้ง

  // อ่านเป็น °C
  double ta = mlx.readAmbientTempC();
  double to = mlx.readObjectTempC();

  // ไลบรารีจะคืน NAN ถ้าอ่านไม่สำเร็จ
  if (isnan(ta) || isnan(to)) {
    Serial.println("[MLX90614] Read failed (NaN). Check wiring/addr.");
    mlx_ok = false; // กัน spam
    return;
  }

  // ส่งขึ้น Blynk
  Blynk.virtualWrite(V5, ta);
  Blynk.virtualWrite(V6, to);

  Serial.printf("MLX90614: Ambient=%.2f °C  Object=%.2f °C\n", ta, to);
}

void tryReconnect() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[WiFi] Reconnecting...");
    WiFi.disconnect();
    WiFi.begin(ssid, pass);
    return;
  }
  if (!Blynk.connected()) {
    Serial.println("[Blynk] Reconnecting...");
    Blynk.connect(5000);
  }
}

// ---------------- Setup & Loop ----------------
void setup() {
  Serial.begin(115200);
  delay(200);
  Serial.println("\nBoot...");

  // LEDs
  pinMode(LED0_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  setLed(LED0_PIN, false);
  setLed(LED1_PIN, false);
  setLed(LED2_PIN, false);

  // VR
  pinMode(VR1_PIN, INPUT);
  pinMode(VR2_PIN, INPUT);

  // I2C + MLX90614
  Wire.begin(I2C_SDA, I2C_SCL, I2C_FREQ);
  if (!mlx.begin()) { // default address 0x5A
    Serial.println("[MLX90614] Not found at default addr (0x5A). Check wiring/pullups.");
  } else {
    Serial.println("[MLX90614] Sensor initialized.");
  }

  // WiFi
  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  Serial.printf("[WiFi] Connecting to: %s\n", ssid);
  WiFi.begin(ssid, pass);
  uint32_t t0 = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - t0 < 20000) {
    delay(500); Serial.print(".");
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("[WiFi] Connected!");
    Serial.print("[WiFi] IP: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("[WiFi] Failed to connect. If captive portal, use normal Wi-Fi/Hotspot.");
  }

  // Blynk non-blocking
  Blynk.config(BLYNK_AUTH_TOKEN);          // default blynk.cloud:443
  // ถ้าทดสอบเครือข่าย/ไฟร์วอลล์: ใช้พอร์ต 80 ชั่วคราว
  // Blynk.config(BLYNK_AUTH_TOKEN, "blynk.cloud", 80);a
  Blynk.connect(10000);

  // Schedulers
  timer.setInterval(5000L, tryReconnect);
  timer.setInterval(300L,  taskSendVR);    // ส่ง VR ทุก ~0.3s
  timer.setInterval(1000L, taskSendMLX);   // อ่าน MLX ทุก 1s
}

void loop() {
  Blynk.run();
  timer.run();
}
