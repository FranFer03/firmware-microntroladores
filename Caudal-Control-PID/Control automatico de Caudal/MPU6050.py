from machine import Pin, I2C
from  time import sleep_ms, ticks_ms
from math importatan, sqrt

i2c = I2C(1,sda=Pin(21),scl=Pin(22),freq=400000)
address_device = 104
RAD_TO_DEG = 57.295779
time_prev = 0
angle = [0,0,0] 

def combine_register_values(h, l):
    if not h[0] & 0x80:
        return h[0] << 8 | l[0]
    return -((h[0] ^ 255) << 8) |  (l[0] ^ 255) + 1

i2c.writeto_mem(104, 0x6B, bytes([0]))
n=0
while True:
    """ Data Acelerometro"""
    accel_x_high = i2c.readfrom_mem(address_device,0x3B,1)
    accel_x_low = i2c.readfrom_mem(address_device,0x3C,1)
    accel_y_high = i2c.readfrom_mem(address_device,0x3D,1)
    accel_y_low = i2c.readfrom_mem(address_device,0x3E,1)
    accel_z_high = i2c.readfrom_mem(address_device,0x3F,1)
    accel_z_low = i2c.readfrom_mem(address_device,0x40,1)
    
    accel_x = combine_register_values(accel_x_high,accel_x_low)/16384
    accel_y = combine_register_values(accel_y_high,accel_y_low)/16384
    accel_z = combine_register_values(accel_z_high,accel_z_low)/16384
#     print("Accel X:{:.3f} Accel Y:{:.3f} Accel Z:{:.3f}".format(accel_x,accel_y,accel_z))
    
    """ Data Giroscopio """
    giro_x_high = i2c.readfrom_mem(address_device,0x43,1)
    giro_x_low = i2c.readfrom_mem(address_device,0x44,1)
    giro_y_high = i2c.readfrom_mem(address_device,0x45,1)
    giro_y_low = i2c.readfrom_mem(address_device,0x46,1)
    giro_z_high = i2c.readfrom_mem(address_device,0x47,1)
    giro_z_low = i2c.readfrom_mem(address_device,0x48,1)
    
    giro_x = combine_register_values(giro_x_high,giro_x_low)/131
    giro_y = combine_register_values(giro_y_high,giro_y_low)/131
    giro_z = combine_register_values(giro_z_high,giro_z_low)/131
#     print("Giro X:{:.3f} Giro Y:{:.3f} Giro Z:{:.3f}".format(giro_x,giro_y,giro_z))
    
    """Data angulo"""
    
    acc_x= atan(accel_y/sqrt(pow(accel_x,2) + pow(accel_z,2)))*RAD_TO_DEG
    acc_y= atan(accel_x/sqrt(pow(accel_y,2) + pow(accel_z,2)))*RAD_TO_DEG
#     print(acc_x*0.02)
    """Calculo muestreo"""
    dt = (ticks_ms() - time_prev)/1000
    time_prev = ticks_ms()
#     print(dt)
    
    """Aplicacion del filtro complementario"""

    angle[0] = 0.98*(angle[0]+giro_x*dt) + 0.02*acc_x
    angle[1] = 0.98*(angle[1]+ giro_y*dt) + 0.02*acc_y
    
    """Integracion con respecto del tiempo"""
    angle[2] = angle[2]*giro_z*dt
    
    print("Angulo X:{:.3f} Giro Y:{:.3f}".format(angle[0],angle[1]))

