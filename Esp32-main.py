from machine import I2C, Pin, ADC
from mpl3115a2 import MPL3115A2
import utime as time
import BlynkLib
import ssd1306
import mlx90614

i2c = I2C(sda=Pin(21), scl=Pin(22))

mpl = MPL3115A2(i2c, mode=MPL3115A2.PRESSURE)
sensor = mlx90614.MLX90614(i2c)

oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

switch = Pin(15, Pin.IN)
led  = Pin(2, Pin.OUT)
volume = ADC(Pin(34))
volume.atten(ADC.ATTN_11DB)

print("Hi ESP32")
oled.text('HI ', 55, 10)
oled.text('ESP32', 40, 20)
oled.text('ANR', 50, 30)
oled.text('&', 60, 40)
oled.text('KSU', 50, 50)
oled.show()
time.sleep(1)

led_count=0


def led_read():
    global led_count
    if switch.value() == 1 and led_count == 0:
        led_count=1
        led.value(1)
        blynk.virtual_write(2,1)
    elif switch.value() == 1 and led_count == 1:
        led_count=0
        led.value(0)
        blynk.virtual_write(2,0) 
    if led_count==1:
        oled.text('LED: ', 0, 10)
        oled.text('ON', 60, 10)
    elif led_count==0:
        oled.text('LED: ', 0, 10)
        oled.text('OFF', 60, 10)
        
def analog_read():
    volume_value = volume.read()
    oled.text('Analog: ', 0, 20)
    oled.text(str(volume_value), 60, 20)
    
def pressure_read():
    pressure = mpl.pressure()
    oled.text('Press: ', 0, 30)
    oled.text(str(pressure), 60, 30)
    #print(pressure)
def temp_read():
    amb = sensor.read_ambient_temp()
    obj = sensor.read_object_temp()
    if amb <= 50:
        oled.text('Ambient: ', 0, 40)
        oled.text(str(amb), 70, 40)
    if obj <= 50:
        oled.text('Object: ', 0, 50)
        oled.text(str(obj), 70, 50)
    time.sleep(0.1)
    
def i2c_scan():
    devices = i2c.scan() # this returns a list of devices
    device_count = len(devices)
    if device_count == 0:
        print('No i2c device found.')
    else:
        pass
        #print(device_count, 'devices found.')
    for device in devices:
        #print('Decimal address:', device, ", Hex address: ", hex(device))
        if device == 90:
            temp_read()
        if device == 96:
            pressure_read()
        else:
            pass
    time.sleep(0.1)

while True:
        oled.fill(0)
        blynk.run()
        i2c_scan()
        led_read()
        analog_read()
        oled.show()
        time.sleep(0.1)


