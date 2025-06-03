from machine import Timer,Pin
from time import sleep_ms

def me(Timer):
    led = Pin(12,Pin.OUT)
    led.on()
    sleep_ms(250)
    led.off()
    sleep_ms(250)
    led.on()
    sleep_ms(250)
    led.off()
    sleep_ms(250)
    print(1)

tim0 = Timer(0)
tim0.init(period=5000, mode=Timer.PERIODIC, callback=me)
