/***************************************************************************
  FileName:        pin_manager.c
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* PORT (pin) configuration                                                */
/*-------------------------------------------------------------------------*/
#include <saml21.h>
#include "pin_manager.h"

void PIN_Manager_init(void){
/****************************************************************************
* Setting direction to Output 
****************************************************************************/
PORT->Group[0].DIRSET.reg = PORT_PA24  | PORT_PA25;//Set pin PA24,PA25 direction to Output
PORT->Group[1].DIRSET.reg = PORT_PB11;//Set pin PB11 direction to Output
/****************************************************************************
* Setting direction to Input 
****************************************************************************/

/****************************************************************************
* Setting the Pull Up
****************************************************************************/

/****************************************************************************
* Setting PINMUX  
****************************************************************************/
/*PORTB --> PINCFG2 --> PMUXEN --> 1 / podłącz pin PB02 do modułu PMUX*/
PORT->Group[1].PINCFG[2].bit.PMUXEN = 1;
/*PORTB --> PINCFG3 --> PMUXEN --> 1 / podłącz pin PB03 do modułu PMUX*/
PORT->Group[1].PINCFG[3].bit.PMUXEN = 1;

/****************************************************************************
* Setting connect PINMUX to Peripheral  
****************************************************************************/
/*PORTB --> PMUX1 --> PMUXO --> 0x3 / podłącz pin PB02 (parzysty pin 2*n) do modułu SERCOM (literka D)*/
PORT->Group[1].PMUX[1].bit.PMUXO = 0x3;
/*PORTB --> PMUX1 --> PMUXE --> 0x3 / podłącz pin PB03 (nieparzysty pin 2*n+1) do modułu SERCOM (literka D)*/
PORT->Group[1].PMUX[1].bit.PMUXE = 0x3;

}