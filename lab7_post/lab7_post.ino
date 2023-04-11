#include <stdint.h>
//#include <ili9341_8_bits.h>
#include <ili9341_8_bits_fast.h>
// Pines usados
//#define LCD_RST PD_0
//#define LCD_CS PD_1
//#define LCD_RS PD_2
//#define LCD_WR PD_3
//#define LCD_RD PA_6
// hay que modificar los pines en la librería
int DPINS[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};
int bandera = 0;
int x = 0;

#include "bitmaps.h"

void setup() {

  pinMode(PA_7, INPUT_PULLUP);
  pinMode(PE_3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PA_7), right, LOW);
  attachInterrupt(digitalPinToInterrupt(PE_3), left, LOW);
  
  Serial.begin(9600);
  Serial.println("Iniciando pantalla...");
  lcdInit();
  Serial.println("Pintando negro");
  lcdClear(NAVY); //Fondo color navy

  //Dibujar estrellas de fondo
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);
  FillRect(random(0,320), random(0,178), 2, 2, WHITE);

  
  //Dibujar grama de piso
    for (int x = 0; x < 319; x++){
      LCD_Bitmap(x, 178, 16, 16, grass);
      LCD_Bitmap(x, 193, 16, 16, grass2);
      LCD_Bitmap(x, 207, 16, 16, grass2);
      LCD_Bitmap(x, 221, 16, 16, grass2);
      x += 15;
    }
}

void loop() {
  if (bandera == 1){
    LCD_Sprite(x, 148, 23, 30, cuphead, 7, 0, 0, 0); //si su ultimo movimiento fue para la izquierda, se queda viendo a la izquierda
  }

  else if (bandera == 2){
    LCD_Sprite(x, 148, 23, 30, cuphead, 7, 0, 1, 0); //si su ultimo movimiento fue para la derecha, se queda viendo a la derecha
  }
}

void right(){
  delay(5); //delay mínimo
  while ((digitalRead(PA_7) == LOW) && (x < 320 - 23)){ //Mientras se este presionando el boton y no esté topando con el borde derecho
    delay(5); //delay 5 ms
    int cup_index = (x/5)%7; //velocidad de animación
    LCD_Sprite(x++, 148, 23, 30, cuphead, 7, cup_index, 0, 0); //Mostrar imagen
    V_line( x - 1, 148, 30, NAVY); //Limpiar rastro
    bandera = 1;  //bandera de movimiento
    }
  }

  void left(){
  delay(5); //delay mínimo
  while ((digitalRead(PE_3) == LOW) && (x > 0)){ //Mientras se este presionando el boton y no esté topando con el borde izquierdo
    delay(5); //delay 5 ms
    int cup_index = (x/5)%7; //velocidad de animación
    LCD_Sprite(x--, 148, 23, 30, cuphead, 7, cup_index, 1, 0); //Mostrar imagen
    V_line( x + 23, 148, 30, NAVY); //Limpiar rastro
    bandera = 2; //bandera de movimiento
    }
  }
