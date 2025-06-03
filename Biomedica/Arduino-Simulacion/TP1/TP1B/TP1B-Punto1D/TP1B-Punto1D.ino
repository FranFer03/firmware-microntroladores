//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que logra que el servo varíe la velocidad de giro de su eje de extremo a extremo 

#include <Servo.h>

Servo myservo;

const int servo = 5;
int pos_pot = 0;
int velocidad = 20;
int pos = 0; 

void setup() {
  myservo.attach(servo);
}

void loop() {
  pos = analogRead(A0);
  pos_pot = map(pos, 1, 1023, 1, 180);
  myservo.write(pos_pot);
  delay(15);             
}
