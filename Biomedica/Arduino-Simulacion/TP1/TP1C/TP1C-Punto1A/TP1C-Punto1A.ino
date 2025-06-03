//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

 //Programa que gira un motor en sentido antihorario
 
const int pin_h=11;  //pin 11 para girar al motor en sentido horario
const int pin_a=10;  //pin 10 para girar al motor en sentido antihorario

void setup() {
    pinMode(pin_h,OUTPUT); 
    pinMode(pin_a,OUTPUT);
}

void loop() {
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_h,LOW);    
}