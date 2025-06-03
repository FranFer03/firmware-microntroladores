//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que mide la cantidad de pulsos por minuto, utilizando un sensor KY-039

#include <math.h>
#include <Wire.h>
#define sensor A5

int c_pulsos=-1;
int pulsos_x_m =0;

long time1 = 0; 
long time2 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int pulso = digitalRead(sensor);
  delay(20);

  if (pulso == 0){
    while (pulso == 0){
      pulso = digitalRead(sensor);
      delay (20);
    } 
    c_pulsos++; 
    if (c_pulsos == 0) time1 = millis(); 
  }
  
  if (c_pulsos > 9){
    time2 = millis(); 
    pulsos_x_m = 60000 * c_pulsos/ (time2 - time1);
    
    Serial.print(pulsos_x_m);
    Serial.println(" Pulsos/min");
    delay (1000);
    c_pulsos=-1;
  }      
}