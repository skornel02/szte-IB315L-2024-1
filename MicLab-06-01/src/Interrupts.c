//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>

#define CLEAR_FLAG(FLAG) FLAG = 0
#define RIGHT_SHIFT 6

extern volatile uint16_t adc_value;

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
  CLEAR_FLAG(ADC0CN0_ADINT);

  adc_value = ADC0 >> RIGHT_SHIFT;
  // Nem vagyok benne biztos miért volt fontos, hogy balra legyen igazítva
  // de pontosság vesztés helyett én inkább shiftelnék.
}

