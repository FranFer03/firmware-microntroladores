//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto


#include <DHT.h>
#include <SFE_BMP180.h>
#include <Wire.h>

const int sensor_t = A0;
int dato=0;
int temperatura=0;
const int p_dato=7;
DHT sensor_h(p_dato,DHT11); 
int H;
SFE_BMP180 sensor_p;
char status;
double P, T=25;
 
void setup()
{
  Serial.begin(9600);
  sensor_h.begin();
  sensor_p.begin();
  delay(200);
}
 
void loop()
{
  dato = analogRead(sensor_t);
  temperatura = dato*0.48875855; 
  Serial.print(temperatura);
  Serial.print("x");
  H = sensor_h.readHumidity();
  Serial.print(H);
  Serial.print("y");
  status = sensor_p.startPressure(3);
      if (status != 0){
        delay(status);
        status = sensor_p.getPressure(P,T);
        Serial.println(P,1);
      }
  delay(50);
}