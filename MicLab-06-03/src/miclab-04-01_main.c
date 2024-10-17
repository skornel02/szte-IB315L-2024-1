//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include "math.h"
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
#define THERMISTOR_25 10000.0f
#define THERMISTOR_B_25_85 3977.0f
#define KELVIN_OFFSET 273.15f
#define THERMISTOR_T_25 (25u + KELVIN_OFFSET)
#define MEASUREMENTS 100
#define MEASUREMENTSF 100.0f

enum {
  UNREAD,
  READ
};

enum {
  UNCONVERTED,
  CONVERTED,
};

volatile uint16_t adc_value = 0;
volatile uint8_t adc_values_index = 0;
volatile uint8_t adc_value_read = READ;
uint8_t adc_value_converted = CONVERTED;
float adc_values;

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET ();

  while (1)
  {
      uint16_t local_adc_value;
      uint16_t thermistor_resistance;
      float temperature_log;
      float temperature;

      if (adc_value_read == UNREAD)
      {
          IE_EA = 0;
          local_adc_value = adc_value;
          IE_EA = 1;

          adc_value_read = READ;
          adc_values += adc_value / MEASUREMENTSF;
      }

      if (adc_values_index == 1)
      {
          adc_value_converted = UNCONVERTED;
      }

      if (adc_values_index == 0 && adc_value_converted == UNCONVERTED)
      {
          adc_value_converted = CONVERTED;

          thermistor_resistance = (RESISTOR_BASE / ((RESOLUTION / adc_values) - 1));
          temperature_log = log(thermistor_resistance / THERMISTOR_25);
          temperature = 1 / ((1 / THERMISTOR_T_25) + (1 / THERMISTOR_B_25_85) * temperature_log) - KELVIN_OFFSET;

          adc_values = 0;
      }
  }
}
