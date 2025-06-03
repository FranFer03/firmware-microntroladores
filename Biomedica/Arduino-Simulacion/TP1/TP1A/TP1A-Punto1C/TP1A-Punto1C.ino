//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que al presionar pulsadores cambio el sentido del giro

#include <Stepper.h>
#define horario 1
#define anti_horario 0

bool hor = false;
bool anti_hor = false;
double rev_pasos = 200;
Stepper myStepper(rev_pasos, 12, 11, 10, 9);


void setup() {
  myStepper.setSpeed(20);
  pinMode(horario,INPUT);
  pinMode(anti_horario,INPUT);
}
void loop() {
  if (digitalRead(horario) == 0) 
    {
      hor = true;
      anti_hor = false;
  }
  if (digitalRead(anti_horario) == 0) 
    {
      hor = false;
      anti_hor = true;
  }
  if (hor == true)  myStepper.step(rev_pasos); 
  if (anti_hor == true)  myStepper.step(-rev_pasos);
}
