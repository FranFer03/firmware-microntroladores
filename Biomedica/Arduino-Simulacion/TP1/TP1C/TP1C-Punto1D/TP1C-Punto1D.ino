//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco

 //Programa que gira un motor en sentido antihorario y luego en sentido horario
 
const int pin_h = 11;  //pin 11 para girar al motor en sentido horario
const int pin_a = 10;  //pin 10 para girar al motor en sentido antihorario
char n; 
String v;
int velocidad;

void setup() {
    Serial.begin(9600);
    pinMode(pin_h,OUTPUT);  //declaramos los pines como salida
    pinMode(pin_a,OUTPUT);
    Serial.println("Ingrese un numero de 0 a 10 para indicar la velocidad de giro"); //Preguntamos la velocidad en un nivel de 0 a 10
}

void loop(){
    if( Serial.available()){ 
        delay(500);       
        v = "";  //declaramos como vacia la cadena "v"
        while (Serial.available()>0){
            n = Serial.read();  //leemos un caraceter y lo guardamos en la variable n
            v += n;    //formamos una cadenas de caraceteres
        }
        Serial.println(v);        
        velocidad = v.toInt(); //convertimos la cadena "v" en una variable entera
        if(velocidad >= 0 and velocidad <= 10){   //preguntamos si el valor ingresado es valido
            velocidad = map(velocidad,0,10,0,255);    //lo convertimos al valor ingresado en un valor analogico de 8 bits
            analogWrite(pin_h,velocidad); 
            digitalWrite(pin_a,LOW);
            Serial.println("");
            Serial.println("Ingrese un numero de 0 a 10 para indicar la velocidad de giro");
        }   
        
        delay(50);
    }
}
