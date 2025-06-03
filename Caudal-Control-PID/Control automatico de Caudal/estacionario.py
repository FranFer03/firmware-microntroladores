from machine import Pin, PWM
import time 
pump = PWM(Pin(12),10000)

while True:
    pump.duty_u16(32768)