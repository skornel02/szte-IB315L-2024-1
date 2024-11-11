//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

#define ONBOARD_LED P1_B4
#define ONBOARD_BTN P0_B2

enum {
  UNSENT,
  SENT
};

enum {
  UNREAD,
  READ
};

volatile uint8_t data_to_send = 0;
volatile uint8_t data_to_send_status = SENT;

volatile uint8_t data_to_read = 0;
volatile uint8_t data_to_read_status = READ;

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

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();
  
  SCON0_TI = 1;

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$

    if (data_to_send_status == UNSENT)
    {
      data_to_send = ONBOARD_BTN ? 'o' : 'L';
      data_to_send_status = SENT;
    }

    if (data_to_read_status == UNREAD)
    {
      ONBOARD_LED = data_to_read == 'o';
      data_to_read_status = READ;
    }
  }                             
}
