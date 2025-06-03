//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que logra que el servo gire su eje en sentido anti horario (extremo a extremo) y luego de 1
//𝑠𝑒𝑔𝑢𝑛𝑑𝑜 este gire en sentido horario

#include <Servo.h>

Servo myservo;  
const int servo = 5;
int pos = 0; 

void setup() {
  myservo.attach(servo); 
}

void loop() {
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
  delay(1000);
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);
    delay(15);              
  }
}