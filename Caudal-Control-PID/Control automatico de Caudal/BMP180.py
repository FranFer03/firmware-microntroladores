from machine import Pin, I2C
from ustruct import unpack
from time import sleep,sleep_ms, sleep_us

i2c = I2C(scl=Pin(22), sda=Pin(21),freq=1000000)
print(i2c.scan())
device_address = 119

while True:
    AC5 = unpack(">h",i2c.readfrom_mem(device_address, 0xB2,2))[0]
    AC6 = unpack(">h",i2c.readfrom_mem(device_address, 0xB4,2))[0]
    MC = unpack(">h",i2c.readfrom_mem(device_address, 0xBc,2))[0]
    MD = unpack(">h",i2c.readfrom_mem(device_address, 0xBE,2))[0]
    i2c.writeto_mem(device_address,0xF4,bytearray([0x2E]))
    sleep_ms(5)
    temp_raw1 = i2c.readfrom_mem(device_address, 0xF6,2)
    temp_raw2 = i2c.readfrom_mem(device_address, 0xF7,2)
    temp_raw1 = temp_raw1[0]
    temp_raw2 = temp_raw2[0]
    temp_raw1 = temp_raw1 << 8
    temp_raw = temp_raw1 | temp_raw2
    #UT = unpack(">h",temp_raw)[0]
    UT = temp_raw
    X1 = (UT-AC6)*AC5/2**15
    X2 = MC*2**11/(X1 + MD)
    B5 = X1 + X2
    T = (B5+8)/2**4/10
    print(T)
