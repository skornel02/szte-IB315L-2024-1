// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>

#define MAGIC_FLAG_OFF 0

//-----------------------------------------------------------------------------
// ADC0EOC_ISR
//-----------------------------------------------------------------------------
//
// ADC0EOC ISR Content goes here. Remember to clear flag bits:
// ADC0CN0::ADINT (Conversion Complete Interrupt Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (ADC0EOC_ISR, ADC0EOC_IRQn)
{
	ADC0CN0_ADINT = MAGIC_FLAG_OFF;

	PCA0CPH0 = ADC0H;
}

