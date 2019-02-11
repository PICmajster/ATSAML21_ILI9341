/***************************************************************************
  FileName:        clock.c
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* CLOCK configuration- core + Peripheral                                  */
/*-------------------------------------------------------------------------*/
//      
//    core clock : 4 MHz
//    spi clock : 4MHz
//    
//
//***************************************************************************
#include <saml21.h>
#include "clock.h"

/*if you need a faster internal clock*/
//void ClockCore_set(void){
///*set the OSC16M value to 16MHz*/
//OSCCTRL->OSC16MCTRL.bit.FSEL = 0b11; 
//while(!OSCCTRL->STATUS.bit.OSC16MRDY);
//}

void Clock_Sercom5_init(void){
/*Start SERCOM5 Clock configuration*/
/*GENCTRLn1 --> SRC --> 0x6  / ustaw źródło zegara Generatora nr 1 na OSC16M*/
GCLK->GENCTRL[1].bit.SRC = GCLK_GENCTRL_SRC_OSC16M_Val;
/*GENCTRLn1 --> GENEN --> 1  / włącz Generator nr 1*/
GCLK->GENCTRL[1].bit.GENEN = 1;
/*PCHCTRL23 --> GEN --> 0x1   / podepnij SERCOM5_Slow do Generatora nr 1*/
GCLK->PCHCTRL[23].bit.GEN = GCLK_PCHCTRL_GEN_GCLK1_Val;
/*PCHCTRL23 --> CHEN --> 1  / włącz kanał dystrybucji zegara SERCOM5 Slow*/
GCLK->PCHCTRL[23].bit.CHEN = 1;
/*PCHCTRL24 --> CHEN --> 1  / włącz kanał dystrybucji zegara SERCOM5 Core*/
GCLK->PCHCTRL[24].bit.CHEN = 1;
}