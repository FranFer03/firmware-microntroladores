//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que muestra en un Display LCD alfanumerico 16x2 la frase "UTN-FRT" con un efecto de corrimiento

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16,2);
    delay(100);
    lcd.setCursor(0,0);
    lcd.print("UTN - FRT");  
}

void loop() {
    lcd.scrollDisplayRight();
    delay(200);      
}

