##############################################################
# Sistemas de Control - Sistema automático de nivel de Tanque
# UTN - FRT - 2022
# Autores : Almeida Juan - Fernandez Francisco
# Graph function of the Cartesian plane in relation to time
# Autor: Sergio Andres Castaño Giraldo
##############################################################
from machine import Pin, I2C, ADC, PWM
import time
from utime import sleep_ms
from ssd1306 import SSD1306_I2C

def plot_time(yp, t, x, y, var = [0.0,40], vpts=[25, 16, 40], hpts = [25, 55, 112]):
    oled.vline(vpts[0], vpts[1], vpts[2], 1)
    oled.hline(hpts[0], hpts[1], hpts[2], 1)
    oled.text(str(round(var[0],1)), vpts[0]-25, hpts[1]-5)
    oled.text(str(round(var[1],1)), vpts[0]-25, vpts[1])
    y[1] = int((yp-var[0])/(var[1]-var[0]) * (vpts[1]-hpts[1]) + hpts[1])
    if t < hpts[2] - hpts[0]:
        x[1] = x[0]+1
    else:
        x[1] = hpts[2]
    oled.line(x[0],y[0],x[1],y[1],1)
    oled.show()
    y[0] = y[1]
    x[0] = x[1]
    if t > hpts[2] - hpts[0]:
        oled.fill_rect(vpts[0],vpts[1],2,vpts[2],0) 
        oled.fill_rect(vpts[0]-25, vpts[1],vpts[0],vpts[2]+5,0)
        oled.scroll(-1,0)
        oled.vline(vpts[0], vpts[1], vpts[2], 1) #x, y, h
        oled.hline(hpts[0], hpts[1], hpts[2], 1) #x, y, w
        oled.text(str(round(var[0],1)), vpts[0]-25, hpts[1]-5)
        oled.text(str(round(var[1],1)), vpts[0]-25, vpts[1])
    else:
        t += 1  
    return t,x,y

def SR_04(trig,eco):
    SOUND = 1/29.1545
    TRIGGER = Pin(trig, Pin.OUT)
    ECHO = Pin(eco, Pin.IN)
    TRIGGER.off()
    time.sleep_us(2)
    TRIGGER.on()
    time.sleep_us(10)
    TRIGGER.off()
    while ECHO.value() == 0:
        start = time.ticks_us()
    while ECHO.value() == 1:
        end = time.ticks_us()
    return (((end - start)*SOUND)/2)

if __name__ == '__main__':
    WIDTH = 128
    HEIGHT = 64
    WIDTH_WATERTANK = 38
    FACTOR = WIDTH_WATERTANK / 65535
    i2c = I2C(1, scl = Pin(22), sda = Pin(21), freq = 200000)
    pump = PWM(Pin(12),10000)
    preset = ADC(Pin(4))
    oled = SSD1306_I2C(WIDTH, HEIGHT, i2c)
    t = 0
    y = [55, 55]
    x = [25, 25]

    while True:
        distance = SR_04(18,19)
        dis = 38 - distance
        set_point = preset.read_u16()* FACTOR
        t,x,y = plot_time(dis,t,x,y)
        oled.fill_rect(0,0,120,15,0)
        oled.text("SP:{:.1f} PL:{:.1f}".format(set_point,dis),0,0)
        oled.show()
        pump.duty_u16(32000)
        print("Set Point: {:.2f} cm  cm  Nivel de agua: {:.2f} cm".format(set_point,dis))
        sleep_ms(100)