//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include <STDIO.H>
// $[Generated Includes]
// [Generated Includes]$

#define UART_BUFFER_SIZE 6u
#define NUM_COUNT 4u
#define BEST_NUMBERRING_SYSTEM_FOR_HUMANS 10u
#define LAST_NUMBER 9u
#define LAST_NUMBER_CHAR '9'

#define MAGIC_NUMBER 1234u

static char buffer[UART_BUFFER_SIZE];
static uint8_t counter = 0;

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


void send_string_uart(const char *str)
{
    while (*str != '\0')
    {
        write_to_uart(*str);
        str++;
    }
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();
  
  sprintf(buffer, "%d\n", MAGIC_NUMBER);

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$

    while(!TMR2CN0_TF2H);
    TMR2CN0_TF2H = 0;
    ++counter;

	if (counter >= 100)
	{
	    send_string_uart(buffer);
	    counter = 0;
	}
  }                             
}
