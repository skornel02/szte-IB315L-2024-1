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

enum {
  LED_T1,
  LED_T2,
  LED_T3,
  LED_T4,
  LED_LEDS
};

enum {
  LED_7 = 1,
  LED_1 = 2,
  LED_2 = 4,
  LED_3 = 8,
  LED_6 = 16,
  LED_5 = 32,
  LED_4 = 64,
};

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

void enable_display(uint8_t display)
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

  DispOutEnable = 1;
}

void disable_display() {
  DispOutEnable = 0;
}

void write_to_spi(uint8_t data_to_send) {
  SPI0CN0_SPIF = 0;
  SPI0DAT = data_to_send;

  // Wait until data is sent out
  while(!SPI0CN0_SPIF) {}

  SPI0CN0_SPIF = 0;
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();
  
  // Shift register beállítása
  // Decoder beállítása

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$


      disable_display();
      //write to spit
      write_to_spi(LED_1 & LED_7);

      //send signal to bit shifter.

      enable_display(LED_LEDS);
  }                             
}
