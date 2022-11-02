/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Systick.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/


/*************STANDARD LIBRARIES**************/
#include "STD_Types.h"
#include "Bit_Math.h"

/*************MICROCONTROLLER SPECIFICATIONS**************/
#include "Mcu_Hw.h"
#include "Mcu_TypeCfg.h"


/*************SYSTICK**************/
#include "Systick.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS                                                                          
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType * ConfigPtr)  

* \Description     : initiate timer
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Re-entrant                                             
* \Parameters (in) : ConfigPtr: this is a pointer to struct that contains:
																	
																	* 	Gpt_ChannelId:
																							timer id which is (TnCCPx or WTnCCPx that x = 1 or 0 and n = 0->5)	
																	*		Gpt_ChannelDirection
																							GPT_COUNT_UP for counting up or GPT_COUNT_DOWN for counting down
																	*		Gpt_GptChannelTickFrequency
																							frequency of the timer
																	*		channelTickMaxValue
																							maximum ticks that the timer will hold
																	*		ChannelMode
																							mode of operation oneshoot or periodic(GPT_MODE_ONESHOT or GPT_MODE_PERIODIC)
																					

* \Parameters (out): void                                                      
* \Return value:   void                                  
*******************************************************************************/

void Systick_TimerInit(void)
{
	STCTRL.B.STCTRL_ENABLE = 0;
	STCTRL.B.STCTRL_INTEN	= 1;
	STCTRL.B.STCTRL_CLK_SRC = 1;
	
}


void Systick_StartTimer(u32 Value)
{
	STRELOAD = Value*MCU_CLOCK_FREQ_KHZ;
	STCURRENT = 5;
	Systick_TimerInit();
	STCTRL.B.STCTRL_ENABLE	= 1;
}


void Systick_StopTimer(void)
{
	STCTRL.B.STCTRL_ENABLE = 0;
}

void Systick_ChangeTimerValue(u32 Value)
{
	STCTRL.B.STCTRL_ENABLE = 0;
	STRELOAD = Value*MCU_CLOCK_FREQ_KHZ;
	STCURRENT = 5;
	
	Systick_TimerInit();
	STCTRL.B.STCTRL_ENABLE	= 1;
	
}



/*******************************************************
 *  END OF FILE: Systick.c
 ******************************************************/



