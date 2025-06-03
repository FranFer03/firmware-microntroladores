//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  if(Serial.available()){
    char estado = Serial.read();
    if(estado == 'e')digitalWrite(13, HIGH);
    if(estado == 'a')digitalWrite(13, LOW);
  }
}