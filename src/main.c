#include "stm32f4_discovery.h"

void delay(uint32_t delayCounts);

void EXTI0_IRQHandler()
{
	STM_EVAL_LEDToggle(LED4);
	EXTI_ClearITPendingBit(EXTI_Line0);
}

int main()
{
	
  /* Initialize Leds mounted on STM32F4-Discovery board */
  STM_EVAL_LEDInit(LED3);
	STM_EVAL_LEDInit(LED4);
	STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);
	
	while(1)
	{
		STM_EVAL_LEDOn(LED3);
		delay(0xFFF);
		STM_EVAL_LEDOff(LED3);
		delay(0xFFF);
	}
}

//a simple delay function used for debouncing
void delay(uint32_t delayCounts)
{
	uint32_t nested_counts;
	while(delayCounts--)
	{
		nested_counts = delayCounts;
		while(nested_counts--);
	}
	
}

