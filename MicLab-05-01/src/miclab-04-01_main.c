//=========================================================
// src/miclab-04-01_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void
SiLabs_Startup (void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

#define REMOVE_INTERRUPT 0
#define READ_INPUT 1
#define MAX_PERCENTAGE 100
#define MIN_PERCENTAGE 0

uint16_t read_adc(void) {
    ADC0CN0_ADINT = REMOVE_INTERRUPT;
    ADC0CN0_ADBUSY = READ_INPUT;
    while (!ADC0CN0_ADINT);

    return ADC0;
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET ();

  while (1)
  {
      const uint16_t MIN_RESISTANCE = 1;
      const uint16_t MAX_RESISTANCE = 1023;

      uint16_t adc_value = read_adc();

      int percentage;

      // Guard against math problems.
      if (adc_value < MIN_RESISTANCE)
      {
          percentage = MIN_PERCENTAGE;
      }
      else if (adc_value > MAX_RESISTANCE)
      {
          percentage = MAX_PERCENTAGE;
      }
      else
      {
         percentage = (adc_value - MIN_RESISTANCE) * (100.0 / (MAX_RESISTANCE - MIN_RESISTANCE));
      }
  }
}