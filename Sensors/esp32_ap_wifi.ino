/*********
  Adapted from Rui Santos - Random Nerd Tutorials
  Modified: Control LED0 (GPIO 2) with Toggle Switch (slider style)
*********/

#include <WiFi.h>

// AP credentials
const char* ssid     = "ESP32-WebServer";
const char* password = "123456789";

// Web server port
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Current LED state
bool ledState = false;  // false = OFF, true = ON

// GPIO for LED0
const int LED0_PIN = 2;

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("\nStarting ESP32 Web Server with Toggle Switch (AP mode)...");

  // Initialize LED pin (active HIGH)
  pinMode(LED0_PIN, OUTPUT);
  digitalWrite(LED0_PIN, LOW);

  // Set WiFi mode to Access Point
  WiFi.mode(WIFI_AP);

  // Start Access Point
  Serial.print("Setting AP…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
  Serial.println("Web server started.");
  Serial.printf("Connect to SSID: %s\n", ssid);
  Serial.printf("Password : %s\n", password);
  Serial.println("Open browser → http://192.168.4.1");
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    header = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;

        if (c == '\n') {
          if (currentLine.length() == 0) {
            // Handle toggle request
            if (header.indexOf("GET /toggle") >= 0) {
              ledState = !ledState;  // สลับสถานะ
              digitalWrite(LED0_PIN, ledState ? HIGH : LOW);
              Serial.println("LED0 toggled → " + String(ledState ? "ON" : "OFF"));
            }

            // HTTP headers
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // HTML + CSS Toggle Switch
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<title>ESP32 LED Control</title>");
            client.println("<style>");
            client.println("body { font-family: Arial, sans-serif; text-align: center; padding: 50px; background: #f4f4f9; }");
            client.println("h1 { color: #333; }");
            client.println(".status { font-size: 1.5em; margin: 20px; font-weight: bold; color: #555; }");
            client.println(".switch { position: relative; display: inline-block; width: 120px; height: 68px; }");
            client.println(".switch input { opacity: 0; width: 0; height: 0; }");
            client.println(".slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; ");
            client.println("background-color: #ccc; transition: .4s; border-radius: 34px; }");
            client.println(".slider:before { position: absolute; content: \"\"; height: 52px; width: 52px; ");
            client.println("left: 8px; bottom: 8px; background-color: white; transition: .4s; border-radius: 50%; }");
            client.println("input:checked + .slider { background-color: #2196F3; }");
            client.println("input:checked + .slider:before { transform: translateX(52px); }");
            client.println("</style></head>");

            client.println("<body><h1>ESP32 LED0 Control</h1>");

            client.println("<p class=\"status\">LED0: " + String(ledState ? "<span style=\"color:#28a745;\">ON</span>" : "<span style=\"color:#dc3545;\">OFF</span>") + "</p>");

            // Toggle Switch
            client.println("<label class=\"switch\">");
            client.print("<input type=\"checkbox\" " + String(ledState ? "checked" : "") + " onchange=\"location.href='/toggle'\">");
            client.println("<span class=\"slider\"></span>");
            client.println("</label>");

            client.println("<p style=\"margin-top: 30px; color: #777;\">Slide to toggle LED0 (GPIO 2)</p>");

            client.println("</body></html>");

            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
