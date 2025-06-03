//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que muestra en un Display LCD los valores leidos de un divisor de tension"

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pote; 
float tension;

void setup() {
    lcd.begin(16,2);
    lcd.setCursor(4,0);
    lcd.print("UTN - FRT ");
    delay(1500);    
}

void loop() {
    pote = analogRead(A0);
    tension = map(pote, 0, 1023, 0, 5000);
    tension = tension/1000;
    lcd.setCursor(0,0);
    lcd.print("Potenciometro: ");
    lcd.setCursor(0,1);
    lcd.print(tension,2);
    lcd.print(" V");
    delay(200);      
}
