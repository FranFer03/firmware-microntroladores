//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que gira el servo motor a 65

#include <Servo.h>

Servo myservo;  
const int servo = 5;
int pos = 0; 

void setup() {
  myservo.attach(servo); 
}

void loop() {
  myservo.write(64); //Con este valor se puede obtener los 65
}