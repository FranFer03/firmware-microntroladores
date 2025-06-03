//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que logra que el servo varíe la velocidad de giro de su eje de extremo a extremo 

#include <Servo.h>

Servo myservo;

const int servo = 5;
int ang = 0;
char pos; 

void setup() {
  Serial.begin(9600);
  Serial.println("Angulo del servo: ");
  myservo.attach(servo);
}

void loop() {
  if (Serial.available() > 0) { 
    ang = Serial.parseInt();
    myservo.write(ang);
  }             
}