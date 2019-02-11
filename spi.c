/***************************************************************************
  FileName:        spi.c
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* SPI configuration                                                       */
/*-------------------------------------------------------------------------*/
//      
//    Reqired SPI connections :
//     - SCK   - PB03 SERCOM5 PAD[1]
//     - MISO  - not used 
//     - MOSI  - PB02 SERCOM5 PAD[0]
//     - CS    - not used
//     
//***************************************************************************
#include <saml21.h>
#include "spi.h"

/*SPI on SERCOM5*/
void SPI_Sercom5_init(void){
/*CTRLA --> ENABLE --> 0 / wyłącz SPI na czas konfiguracji*/
SERCOM5->SPI.CTRLA.bit.ENABLE = 0;
/*wait for synchro*/
while(SERCOM5->SPI.SYNCBUSY.bit.ENABLE == 1);
/*CTRLA --> MODE --> 0x3  / włącz tryb SPI MASTER dla SERCOM*/
SERCOM5->SPI.CTRLA.bit.MODE = 0x3;
/*CTRLB --> RXENABLE --> 0 / wyłącz RX*/
SERCOM5->SPI.CTRLB.bit.RXEN = 0;
/*wait for synchro*/
while(SERCOM5->SPI.SYNCBUSY.bit.CTRLB);
/*CTRLA --> DIPO -->  0x2 / w trybie MASTER przyporządkuj do PAD[2] MISO ale nie używamy go*/
SERCOM5->SPI.CTRLA.bit.DIPO = 0x2;
/*CTRLA --> DOPO -->  0x0 / w trybie MASTER przyporządkuj do PAD[0] MOSI a do PAD[1] CLK*/
SERCOM5->SPI.CTRLA.bit.DOPO = 0;
/*BAUD --> BAUD --> 0 / ustaw na 8 bitach wartość Baud Generator*/
SERCOM5->SPI.BAUD.reg = 0x0; //for Baud = 0 --> f max = F Core / 2
/*Interrupt flag TXC on*/
SERCOM5->SPI.INTENSET.bit.TXC = 1;
/*CTRLA --> ENABLE --> 0 / włącz SPI*/
SERCOM5->SPI.CTRLA.bit.ENABLE = 1;
/*wait for synchro*/
while(SERCOM5->SPI.SYNCBUSY.bit.ENABLE == 1);
/*End  SPI configuration*/
}

void SPI_Sercom5_send(uint8_t data)
{  
    SERCOM5->SPI.DATA.reg = data; //send data
     /*wait for transfer complete*/
    while(!SERCOM5->SPI.INTFLAG.bit.TXC);
       
}