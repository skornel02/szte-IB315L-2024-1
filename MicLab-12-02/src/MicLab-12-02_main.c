//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                // SFR declarations
#include <SI_EFM8BB1_Defs.h>

#define WD_DISABLE_A 0xDE
#define WD_DISABLE_B 0xAD

#define SYSCLOCK 24500000u
#define SYS_PRESCALER 8u

#define TIMER3_PRESCALER 12u
#define TIMER3_BASE_CLOCK (SYSCLOCK / (SYS_PRESCALER * TIMER3_PRESCALER))
#define TIMER3_TARGET_HZ 10u
#define TIMER3_SIZE 65536u
#define TIMER3_RELOAD (TIMER3_SIZE - (TIMER3_BASE_CLOCK / TIMER3_TARGET_HZ))
// Ez csak 8.17 Hz képlet szerint

#define LED0 P1_B4

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
  // Disable the watchdog here

  // Erre nincs konstans az Enumsban.
  WDTCN = WD_DISABLE_A;
  WDTCN = WD_DISABLE_B;

  XBR2 |= XBR2_XBARE__ENABLED;

  P1MDOUT |= P1MASK_B4__COMPARED;

  IE_EA = 1;
  EIE1 |= EIE1_ET3__ENABLED;

  TMR3CN0 |= TMR3CN0_TR3__RUN;
  TMR3CN0 &= ~TMR3CN0_T3SPLIT__BMASK;
  TMR3CN0 &= ~TMR3CN0_T3XCLK__BMASK;

  TMR3RLH = TIMER3_RELOAD >> 2;
  TMR3RLL = TIMER3_RELOAD;
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
// Note: the software watchdog timer is not disabled by default in this
// example, so a long-running program will reset periodically unless
// the timer is disabled or your program periodically writes to it.
//
// Review the "Watchdog Timer" section under the part family's datasheet
// for details. To find the datasheet, select your part in the
// Simplicity Launcher and click on "Data Sheet".
//-----------------------------------------------------------------------------
int main (void)
{
  while (1) {}                             // Spin forever
}

void timer3_interrupt (void) interrupt TIMER3_IRQn
{
  TMR3CN0 &= ~TMR3CN0_TF3H__BMASK;

  LED0 = ~LED0;
}
