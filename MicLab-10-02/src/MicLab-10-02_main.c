//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

#define UART_BUFFER_SIZE 6u
#define NUM_COUNT 4u
#define BEST_NUMBERRING_SYSTEM_FOR_HUMANS 10u
#define LAST_NUMBER 9u
#define LAST_NUMBER_CHAR '9'

#define MAGIC_NUMBER 1234u

static char buffer[UART_BUFFER_SIZE];

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

void sprintf(char* local_buffer, uint16_t num)
{
  uint8_t i;
  for (i = 0; i < NUM_COUNT; i++)
  {
    local_buffer[NUM_COUNT - i - 1] = LAST_NUMBER_CHAR - (LAST_NUMBER - (num % BEST_NUMBERRING_SYSTEM_FOR_HUMANS));
    num = num / BEST_NUMBERRING_SYSTEM_FOR_HUMANS;
  }

  local_buffer[NUM_COUNT] = '\n';
  local_buffer[NUM_COUNT + 1] = '\o';
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();
  
  sprintf(buffer, MAGIC_NUMBER);

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$

    send_string_uart(buffer);
  }                             
}
