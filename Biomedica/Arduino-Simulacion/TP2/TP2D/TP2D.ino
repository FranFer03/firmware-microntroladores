//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que detecta la presencia de Monoxido de carbono (CO) usando un sensor MQ-7

#define GAS 9
int gas_sensor = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Inicio de sensado");
  pinMode(GAS,INPUT);
}

void loop() {
  gas_sensor = digitalRead(GAS);
  if (gas_sensor == 0) Serial.println("Sin presencia de Monoxido de Carbono");
  else if (gas_sensor == 1) Serial.println("Monoxido de Carbono detectado");
  delay(1000);
}
