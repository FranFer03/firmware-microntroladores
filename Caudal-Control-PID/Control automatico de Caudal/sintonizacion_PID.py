from machine import Pin, PWM, ADC, I2C, Timer
from utime import sleep_ms
import time

pwm = PWM(Pin(12)) 
pwm.freq(40000)

K = 30
tau = 820
theta = 3
Ts = 10;                  
L = theta + Ts/2

e = [0,0,0]
u = [0,0]

#Calcular distancia
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

#Algoritmo para desplazar el valor previo al elemento anterior
def update_past(v,kT):
   for i in range(1,kT,1):
      v[i-1]=v[i]
   return v

#Calculo PID
def PID_Controller(u, e, q0, q1, q2):
    # Controle PID
    # e[2] = e(k)
    # e[1] = e(k-1)
    # e[0] = e(k-2)
    # u[0] = u(k-1)
    lu = u[0] + q0*e[2] + q1*e[1] + q2*e[0]; #Ley del controlador PID discreto
    
    # Anti - Windup
    if (lu >= 100.0):        
        lu = 100.0
        
    if (lu <= 0.0):
        lu = 0.0
    return(lu)

#Calcualo del valor de la salida    
def temporizador(timer):
   global u, e, q0, q1, q2 
   #Actualiza los vectores u y e
   u = update_past(u,len(u));
   e= update_past(e,len(e));
   #Calcula el error actual
   e[len(e)-1] = setpoint - level;
   #Calcula la Acción de Control PID
   u_end = PID_Controller(u, e, q0, q1, q2);  #Max= 100, Min=0
   u[len(u)-1] = u_end
   velocidad = int(u[len(u)-1] * 65535 /100);
   #Aplica la acción de control en el PWM
   pwm.duty_u16(velocidad)

#Funcion principal
def main():
    global level,setpoint, q0, q1, q2, u, e

    setpoint = 14
    
    kp=2
    ti=27
    td=2

    q0=kp*(1+Ts/(2*ti)+td/Ts)
    q1=-kp*(1-Ts/(2*ti)+(2*td)/Ts)
    q2=(kp*td)/Ts
    
    tim = Timer(0)
    tim.init(period=100, mode=Timer.PERIODIC, callback=temporizador)

    while True:
        global level
        level = SR_04(18,19)
        print("Set Point: {:.2f} cm   Nivel de agua: {:.2f} cm".format(setpoint,level))
        sleep_ms(500)
    
if __name__ == '__main__':
    main()