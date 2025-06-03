##############################################################
# Sistemas de Control - Prueba de HCSR04
# UTN - FRT - 2022
# Autores : Almeida Juan - Fernandez Francisco
##############################################################
from machine import Pin,PWM
import time 
SOUND = 1/29.1545
setpoint = 8

TRIGGER = Pin(18, Pin.OUT)
ECHO = Pin(19, Pin.IN)
pump = PWM(Pin(12),10000)

while True:
    TRIGGER.off()
    time.sleep_us(2)
    TRIGGER.on()
    time.sleep_us(10)
    TRIGGER.off()
    while ECHO.value() == 0:
        start = time.ticks_us()
    while ECHO.value() == 1:
        end = time.ticks_us()
    distance = 38 - ((end - start)*SOUND)/2
    print("{:.2f} cm".format(distance))
    time.sleep_ms(100)
    if distance <= setpoint:
        pump.duty_u16(65530)
    else:
        pump.duty_u16(0)

