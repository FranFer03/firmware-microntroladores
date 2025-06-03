//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto 

 //Programa que gira un motor en sentido antihorario y luego en sentido horario
 
const int pin_h = 11;  //pin 11 para girar al motor en sentido horario
const int pin_a = 10;  //pin 10 para girar al motor en sentido antihorario
char sentido; 

void setup() {
    Serial.begin(9600);
    pinMode(pin_h,OUTPUT);
    pinMode(pin_a,OUTPUT);
    Serial.println("Ingrese:");
    Serial.println("'a' para girar en sentido antihorario");
    Serial.println("'h' para girar en sentido horario");
}

void loop() {
    if(Serial.available()>0){
        sentido = Serial.read();
        if(sentido == 'a'){
          //giramos al motor en sentido antihorario
          digitalWrite(pin_a,HIGH); 
          digitalWrite(pin_h,LOW);
          Serial.println("Girando en sentido antihorario");
        }
        if(sentido == 'h'){
          //giramos al motor en sentido horario
          digitalWrite(pin_a,LOW); 
          digitalWrite(pin_h,HIGH);
          Serial.println("Girando en sentido horario");
        }
    }
    delay(500);    
}

