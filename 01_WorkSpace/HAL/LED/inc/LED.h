/**************************************************

  * File description
  
****************************************************/

/**
*
*   \file   LED.h
*   \brief  
*   
*   \details
*
******************************************************/


#ifndef LED_H_
#define LED_H_


/**************************************************

  * INCLUDES
  
****************************************************/

#include 	"STD_Types.h"
#include	"LED_Config.h"

/**************************************************

  * GLOBAL CONSTANT MACROS
  
****************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void	Led_Init(u8 PortId, u8 PinId);

void 	Switch_Init(void);

void  Led_ON(void);

void  Led_OFF(void);

 
	
void  Led_Activate(u32 On_Time);


#endif /*LED_H_*/

/**************************************************

  * END FILE LED.h
  
****************************************************/






