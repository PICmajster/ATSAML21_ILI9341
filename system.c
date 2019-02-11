/***************************************************************************
  FileName:        system.c
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* system configuration                                                    */
/*-------------------------------------------------------------------------*/

#include <saml21.h>
#include "system.h"
#include "clock.h"
#include "pin_manager.h"
#include "spi.h"

void SYSTEM_init(void)
{
    PIN_Manager_init();
    Clock_Sercom5_init();//ważna kolejność
    SPI_Sercom5_init();
    
}