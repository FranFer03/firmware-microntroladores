//Universidad Tecnologica Nacional - Facultad Regional Tucuman
//Departamento de Ingenieria Electronica - Sistemas de Control Biomedico
//by Fernandez Francisco Alberto

//Programa que muestra en un Display LCD grafico como varia el valor de un divisor de tension en funcion del tiempo

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 13 - Serial clock out (SCLK)
// pin 11 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 5, 4, 3);

void ejes(void) {
  // Dibujamos la etiqueta del eje y
  display.setRotation(1);  //rotamos 90 grados para poder escribir desde abajo hacia arriba
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(6,0);
  display.println("Tension");  
  // Dibujamos la etiqueta del eje x
  display.setRotation(0);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(20,40);
  display.println("Tiempo");
  //Dibujamos el eje y
  display.drawLine(8, 0, 8, 39, BLACK);
  //Dibujamos el eje x
  display.drawLine(8, 39, 83, 39, BLACK);
  display.display();
}
 

void setup()   {
  Serial.begin(9600);
  display.begin();    //iniciamos el display
  display.setContrast(50);    //configuramos el contraste de la pantalla
  display.display(); //mostramos la pantalla de bienvenida
  delay(1000);
  display.clearDisplay();   //limpiamos la pantalla
  //Escribimos en pantalla el msj UTN - FRT antes de comenzar
  display.setTextSize(1);   
  display.setTextColor(BLACK);  
  display.setCursor(20,20);
  display.println("UTN - FRT");
  display.display(); 
  delay(2000);
  display.clearDisplay();
}


void loop() {
  ejes();   //llamamos a la funcion que genera los ejes coordenados
  for(int16_t i=9; i<84; i++){
      int pot = analogRead(A2);   //leemos el valor del divisor de tension a traves de un pin analogico, devolviendo un valor entre 0 y 1023
      int16_t v = map(pot, 0, 1023, 38, 0);   //mapeamos pot para convertirlo en un valor entre 38 y 0, lo que nos da la variacion en la tension
      //para 0v -> 0(en la variable pot) -> fila 38 en la pantalla(abajo)
      //para 5v -> 1023(en la variable pot) -> fila 0 en la pantalla(arriba)
      //la varible i nos da la columna y por lo tanto el progreso en el tiempo
      display.drawPixel(i, v, BLACK);     //dibujamos un punto que representa la tension en funcion del tiempo
      display.display();
      delay(500);      
  }
  display.clearDisplay();   //cuando se llega al final de la pantalla, limpiamos y volvemos a comenzar
}
