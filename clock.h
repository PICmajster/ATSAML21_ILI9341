/***************************************************************************
  FileName:        clock.h
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* CLOCK configuration- core + Peripheral                                  */
/*-------------------------------------------------------------------------*/
//      
//    core clock : 4 MHz
//    SERCOM0 clock : 4MHz
//    
//
//***************************************************************************

//void ClockCore_set(void);
void Clock_Sercom5_init(void);
