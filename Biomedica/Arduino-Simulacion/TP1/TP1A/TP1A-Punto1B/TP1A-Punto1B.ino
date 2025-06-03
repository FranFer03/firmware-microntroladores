//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

 //Programa que gira un motor en sentido antihorario

#include <Stepper.h>

double rev_pasos = 200;
Stepper myStepper(rev_pasos, 12, 11, 10, 9);

void setup() {
  myStepper.setSpeed(20);
}
void loop() {
   myStepper.step(-rev_pasos);
   delay(500);
}
