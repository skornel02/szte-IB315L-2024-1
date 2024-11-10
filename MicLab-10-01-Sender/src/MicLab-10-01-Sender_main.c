//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

#define ONBOARD_BTN P0_B2

enum {
  PRESSED,
  RELEASED
};

static uint8_t button_state = RELEASED;

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

void write_to_uart(uint8_t data_to_send)
{
  SBUF0 = data_to_send;

  while (!SCON0_TI);
  SCON0_TI = 0;
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();
  
  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$
    if (!ONBOARD_BTN && button_state == RELEASED) {
        write_to_uart('L');
        button_state = PRESSED;
    }

    if (ONBOARD_BTN && button_state == PRESSED) {
        button_state = RELEASED;
    }
  }                             
}
