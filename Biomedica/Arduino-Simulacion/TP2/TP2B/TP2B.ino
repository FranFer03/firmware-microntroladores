//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Lectura del sensor DHT11 y visualizacion de valores por PC

#include "DHT.h"

#define DHTTYPE DHT11 
DHT dht(7, DHTTYPE);

float hum = 0; 
float temp = 0; 

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  hum =  dht.readHumidity();
  temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp)) {
    Serial.println(F("Fallo la lectura del sensor!!"));
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
}