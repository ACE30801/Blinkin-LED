/*****includes*****/


#include "Bit_Math.h"
#include "Platform_Types.h"
#include "STD_Types.h"
#include "Mcu_Hw.h"
#include "Cpu_Driver.h"

#include "Dio.h"
#include "Port.h"
#include "Systick.h"
#include "IntCtrl.h"
#include "LED.h"

#include "Port_Lcfg.h"

void Systick_CountEnd(void)  ;
void Get_Time(u32 *);

/*---------- time variables----------*/
static u32 T_ON;
static u32 T_OFF;


/*******main function*******/

int main(void)
{
	
	CpuDriver_EnableGlobalInterrupt();
	
	Led_Init(LED_PORT, LED_PIN);
	Switch_Init();
		
	
	 
	while(1)
	{
			/*wait for switch 1 to start the system*/
			while(!(Dio_ReadChannel(SW1_PORT, SW1_PIN)))
			{
					/*dummy code*/
					u16 x = 0;
					
				if(x>0)
				{
					x--;
				}
				else
				{
					x++;
				}
			
			}
			/*first click to set On time*/
			if(Dio_ReadChannel(SW1_PORT, SW1_PIN))
			{
					
				/*Wait until Switch is released*/
				while(Dio_ReadChannel(SW1_PORT, SW1_PIN));
				
				T_ON=0; /*Start counting from 0 (if the user wanted to re-enter new values during run time)*/
				
				
				/*enter T_ON while the switch 1 isn't pressed again*/
				while(!(Dio_ReadChannel(SW1_PORT, SW1_PIN)))
				{
					Get_Time(&T_ON);
				}
				
				/*you will not reach here until switch 1 is pressed again*/
				
				/*the second click*/
				/*Wait until Switch is released*/
				while(Dio_ReadChannel(SW1_PORT, SW1_PIN));
				
				T_OFF=0; /*Start counting from 0 (if the user wanted to re-enter new values during run time)*/
				
				
				/*enter T_OFF while the switch 1 isn't pressed again*/
				while(!(Dio_ReadChannel(SW1_PORT, SW1_PIN)))
				{
					Get_Time(&T_OFF);
				}
				
				/*You will not reach here until switch 1 is pressed again (for the third time)*/
				
				/*Wait until Switch is released*/
				while(Dio_ReadChannel(SW1_PORT, SW1_PIN));
				
				/*if the user didn't enter T_ON or T_OFF*/
				if(T_ON ==0 || T_OFF ==0)
				{
					/*don't activate the system and wait for a valid data (go to the while loop at the start of the code)*/
				}
				else
				{
						
					
						/*Activate the LED code*/
						
						Led_Activate(T_ON);
				}
			}
			
	
	
	}


}

void Systick_CountEnd(void)  
{
	static u8 State = 1;
	if(State)
	{
		Led_OFF();
		Systick_ChangeTimerValue(T_OFF);
		State = 0;
	}
	else
	{
		Led_ON();
		Systick_ChangeTimerValue(T_ON);
		State = 1;
	}
}


void Get_Time(u32* Time)
{
	/*if button 2 is clicked on*/
	if(Dio_ReadChannel(SW2_PORT, SW2_PIN))
	{
		
		/*wait until the button is released*/
		while(Dio_ReadChannel(SW2_PORT, SW2_PIN));
		
		/*increase T_ON by 1000 that each click is 1000 mseconds(1 second) */
		*Time +=1000;
	}
	else
	{
		/*Do Nothing*/
	}

}

