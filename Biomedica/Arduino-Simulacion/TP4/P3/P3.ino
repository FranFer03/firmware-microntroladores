//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

#define sensor A0
float data = 0;
float temp = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  data = analogRead(sensor);
  temp = data * 5 * 100 / 1023;
  Serial.println(temp);
  delay(50);
}