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

#define RESOLUTION 65536.0f
#define REFERENCE_VOLTAGE_MV 3300u
#define RESISTOR_BASE 10000u

volatile uint16_t adc_value = 0;

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET ();

  // V_in

  while (1)
  {
      uint16_t local_adc_value;
      uint16_t thermistor_resistance;

      // save local adc value, can be interrupted after.
      IE_EA = 0;
      local_adc_value = adc_value;
      IE_EA = 1;

      thermistor_resistance = (RESISTOR_BASE / ((RESOLUTION / adc_value) - 1));
  }
}
