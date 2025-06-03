//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que logra que el servo varíe la velocidad de giro de su eje de extremo a extremo 

#include <Servo.h>

Servo myservo;  
const int servo = 5;
int velocidad = 20;
int pos = 0; 

void setup() {
  myservo.attach(servo);
}

void loop() {
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(velocidad);
  }
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);
    delay(velocidad);              
  }
  velocidad -=5;
  if (velocidad < 0) velocidad = 20; 
}