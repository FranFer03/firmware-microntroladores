//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Lectura del sensor BMP180 y visualizacion de valores por PC

#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
int32_t pre = 0;
int32_t pre_at = 0;

void setup() {
  Serial.begin(9600);
  bmp.begin();
}
  
void loop() {
    pre = bmp.readPressure();
    pre_at = bmp.readSealevelPressure();

    Serial.print("Presion = ");
    Serial.print(pre);
    Serial.println(" Pa");

    Serial.print("Presion sobre el nivel del mar = ");
    Serial.print(pre_at);
    Serial.println(" Pa");
    
    Serial.println();
    delay(500);
}