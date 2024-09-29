#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#define ONBOARD_LED P1_B4
#define ONBOARD_BTN P0_B2

// This routine changes the state of the LED whenever Timer2 overflows.
//
SI_INTERRUPT(TIMER2_ISR, TIMER2_IRQn)
{
   TMR2CN0_TF2H = 0;
   if (!ONBOARD_BTN)
   {
	   ONBOARD_LED = !ONBOARD_LED;
   }
   else
   {
	   ONBOARD_LED = 1;
   }
}
