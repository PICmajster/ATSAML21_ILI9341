/***************************************************************************
  FileName:        main.c
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* ILI9341 LCD TFT 320x240 SPI test                                        */
/*-------------------------------------------------------------------------*/
//      
//    Signal LCD ---> MCU ATSAML21G18B
//     CS     (Chip Select)     --> Ground
//     RESET                    --> PA25
//     DC/RS  (Command / Data)  --> PA24
//     MOSI   (Serial Data)     --> PB02
//     SCK    (Serial Clock)    --> PB03
//     LED                      --> +3.3Vx
//
//***************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <saml21.h>
#include "delay.h"
#include "system.h"
#include "ili9341.h"
#include "heros.h"
#include "flaga.h"
#include "spi.h"

void main(void) {
 /* Initialize the SAM system */
SYSTEM_init();

ili9341_init();
 
setOrientation(LANDSCAPE_REV); //PORTRAIT, LANSCAPE, PORTRAIT_REV, LANDSCAPE_REV

//hline(10, 40, 50, YELLOW);
//pixel(30,30,RED);
//fillRectangle(10, 10, 60, 60, BLUE);
//hline(50, 50, 150, WHITE);
//circle(120, 120, 50, YELLOW);
//putChar('A', 40, 20,3, YELLOW);
putString("ATSAML21", 175, 30, 3, RED);
putString("ILI9341", 205, 80, 2, ORANGE);
putString("strefapic.blogspot.com", 20, 200, 2, YELLOW);
//putInteger(1643,60, 120,3,YELLOW);
//putFloat(124.7, 30, 37, 3, YELLOW);
//block(30, 30, 6, 2, YELLOW);
//barGraf(30, 160, 6, 20, 2, YELLOW, BLUE);
eqGraf("Volume ", 30, 160, 4, 2, GREEN, RED);
//DrawBitmapRGB565(heros, 160, 128, 0, 0);
DrawBitmapRGB565(flaga, 170, 128, 0, 0);
//drawRoundRect(180, 30, 40,60, 15, YELLOW);
//fillRoundRect(180, 30, 40, 60, 15, YELLOW);

while (1) {
      
      
   }

}
