
#include <stdint.h>
#include <ili9341_8_bits.h>
// Pines usados
//#define LCD_RST PD_0
//#define LCD_CS PD_1
//#define LCD_RS PD_2
//#define LCD_WR PD_3
//#define LCD_RD PA_6
// hay que modificar los pines en la librería
int DPINS[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};

#include "bitmaps.h"

void setup() {
  
  lcdSetDataPins(DPINS);
  Serial.begin(9600);
  Serial.println("Iniciando pantalla...");
  lcdInit();
  Serial.println("Pintando negro");
  lcdClear(NAVY); //Fondo Navy

  //DIBUJAR SILUETAS DE EDIFICIO Y SUELO
  FillRect(100, 100, 5, 105, BLACK);
  FillRect(100, 100, 50, 5, BLACK);
  FillRect(145, 100, 5, 105, BLACK);
  
  FillRect(0, 205, 320, 5, BLACK);
  FillRect(0, 210, 320, 40, DARKGREY);
  
  FillRect(105, 105, 40, 100, PURPLE);

  //DIBUJAR ESTRELLAS DE FONDO
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);
  FillRect(random(0,95), random(0,200), 2, 2, WHITE);

  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);
  FillRect(random(150,340), random(0,200), 2, 2, WHITE);

  //DIBUJAR EDIFICIO
  FillRect(110, 110, 5, 5, WHITE);
  FillRect(110, 120, 5, 5, YELLOW);
  FillRect(110, 130, 5, 5, WHITE);
  FillRect(110, 140, 5, 5, YELLOW);
  FillRect(110, 150, 5, 5, WHITE);
  FillRect(110, 160, 5, 5, YELLOW);
  FillRect(110, 170, 5, 5, WHITE);
  FillRect(110, 180, 5, 5, YELLOW);

  FillRect(123, 110, 5, 5, YELLOW);
  FillRect(123, 120, 5, 5, WHITE);
  FillRect(123, 130, 5, 5, YELLOW);
  FillRect(123, 140, 5, 5, WHITE);
  FillRect(123, 150, 5, 5, YELLOW);
  FillRect(123, 160, 5, 5, WHITE);
  FillRect(123, 170, 5, 5, YELLOW);
  FillRect(123, 180, 5, 5, WHITE);

  FillRect(136, 110, 5, 5, WHITE);
  FillRect(136, 120, 5, 5, YELLOW);
  FillRect(136, 130, 5, 5, WHITE);
  FillRect(136, 140, 5, 5, YELLOW);
  FillRect(136, 150, 5, 5, WHITE);
  FillRect(136, 160, 5, 5, YELLOW);
  FillRect(136, 170, 5, 5, WHITE);
  FillRect(136, 180, 5, 5, YELLOW);

  FillRect(115, 190, 20, 15, DARKCYAN);
  FillRect(115, 190, 20, 2, LIGHTGREY);
  FillRect(135, 190, 2, 15, LIGHTGREY);
  FillRect(115, 190, 2, 15, LIGHTGREY);

  FillRect(135, 90, 2, 10, BLACK);
  FillRect(130, 92, 12, 2, BLACK);
  FillRect(130, 95, 12, 2, BLACK);

  //DIBUJAR ARBOL
  FillRect(198, 190, 5, 15, MAROON);
  FillRect(190, 180, 10, 10, DARKGREEN);
  FillRect(200, 180, 10, 10, DARKGREEN);
  FillRect(185, 175, 20, 5, DARKGREEN);
  FillRect(200, 175, 15, 5, DARKGREEN);
  FillRect(185, 160, 30, 15, DARKGREEN);

 delay(1000); //delay de 1s
 lcdClear(NAVY); //Limpiar pantalla con fondo navy

 LCD_Bitmap(10, 10, 58, 80, frisk); //Dibujar a frisk
 LCD_Bitmap(180, 10, 92, 112, cuphead); //Dibujar a cuphead
 LCD_Bitmap(100, 100, 20, 29, ness); //Dibujar a ness
 
}

void loop() {

}
