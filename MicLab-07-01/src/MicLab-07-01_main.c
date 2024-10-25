//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

#define DispClock P0_B0
#define DispData P0_B2
#define DispOutEnable P0_B3

#define DecoderA P1_B1
#define DecoderB P1_B2
#define DecoderC P0_B4

// Displays
enum {
  LED_T1,
  LED_T2,
  LED_T3,
  LED_T4,
  LED_LEDS
};

// Leds on display
enum {
  LED_7 = 1,
  LED_1 = 2,
  LED_2 = 4,
  LED_3 = 8,
  LED_6 = 16,
  LED_5 = 32,
  LED_4 = 64,
};

#define LEDS_TO_ACTIVE ~(LED_1 | LED_7)

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

// Enable selected display.
// Tudom hogy most overkill, de hasznos lehet még
void select_display(uint8_t display)
{
  switch (display) {
    case LED_T1:
      DecoderA = 0;
      DecoderB = 0;
      DecoderC = 0;

      break;
    case LED_T2:
      DecoderA = 1;
      DecoderB = 0;
      DecoderC = 0;

      break;
    case LED_T3:
      DecoderA = 0;
      DecoderB = 1;
      DecoderC = 0;

      break;
    case LED_T4:
      DecoderA = 1;
      DecoderB = 1;
      DecoderC = 0;

      break;
    case LED_LEDS:
      DecoderA = 0;
      DecoderB = 0;
      DecoderC = 1;

      break;

    default:
      break;
  }
}

void write_to_spi(uint8_t data_to_send) {
  SPI0CN0_SPIF = 0;
  SPI0DAT = data_to_send;

  // Wait until data is sent out
  while(!SPI0CN0_SPIF);

  SPI0CN0_SPIF = 1;
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();

  select_display(LED_LEDS);

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$


	  // disable leds
	  DispOutEnable = 1;

      //write to spi
      write_to_spi(LEDS_TO_ACTIVE);

      //send signal to bit shifter.
	  DispOutEnable = 0;
  }                             
}
