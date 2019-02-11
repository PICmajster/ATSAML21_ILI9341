/***************************************************************************
  FileName:        delay.h
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* Delay function                                                          */
/*-------------------------------------------------------------------------*/
#include <saml21.h>
#include "delay.h"

void portable_delay_cycles(uint32_t n)
{
    __asm (
    "loop: DMB    \n"
    #ifdef __ICCARM__
    "SUBS r0, r0, #1 \n"
    #else
    "SUB r0, r0, #1 \n"
    #endif
    "CMP r0, #0  \n"
    "BNE loop         "
    );
}