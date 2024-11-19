//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

#define ONBOARD_BTN P0_B2
#define STEPS 4u
#define BUTTON_DEBOUNCE 64u
#define MAGIC_FLAG_OFF 0

enum {
  RELEASED,
  PRESSED,
};

enum {
  HANDLED,
  UNHANDLED
};

enum {
  STEP0,
  STEP25,
  STEP50,
  STEP75,
};

static uint8_t button_last_status = RELEASED;
static uint8_t button_status = RELEASED;
static uint8_t button_counter = 0;
static uint8_t led_step_status = HANDLED;

static uint8_t pwm_steps[STEPS] = {0u, 64u, 128u, 192u};
static uint8_t current_step = STEP0;

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
  
  PCA0CPH0 = pwm_steps[current_step];

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$

	  if (!ONBOARD_BTN)
	  {
		  if (button_last_status == RELEASED)
		  {
			  button_last_status = PRESSED;
		  }
		  else if (button_counter < BUTTON_DEBOUNCE)
		  {
			  ++button_counter;
		  }
		  else
		  {
			  button_status = PRESSED;
			  button_counter = 0;
		  }
	  }
	  else
	  {
		  if (button_last_status == PRESSED)
		  {
			  button_last_status = RELEASED;
		  }
		  else if (button_counter < BUTTON_DEBOUNCE)
		  {
			  ++button_counter;
		  }
		  else
		  {
			  button_status = RELEASED;
			  button_counter = 0;
		  }
	  }

      if (button_status == PRESSED)
      {
    	  TMR2L = 0;
    	  TMR2H = 0;
    	  TMR2CN0_TF2H = MAGIC_FLAG_OFF;
    	  while(!TMR2CN0_TF2H);
    	  TMR2CN0_TF2H = MAGIC_FLAG_OFF;

    	  led_step_status = UNHANDLED;
    	  button_status = RELEASED;
      }

      if (led_step_status == UNHANDLED)
      {
          current_step = (current_step + 1) % STEPS;

          PCA0CPH0 = pwm_steps[current_step];
          led_step_status = HANDLED;
      }
  }                             
}
