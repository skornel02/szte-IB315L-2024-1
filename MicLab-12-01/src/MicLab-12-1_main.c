//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                // SFR declarations

#define WD_DISABLE_A 0xDE
#define WD_DISABLE_B 0xAD

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
  // Disable the watchdog here.

  // Erre nincs konstans az Enumsban.
  WDTCN = WD_DISABLE_A;
  WDTCN = WD_DISABLE_B;

  XBR2 |= XBR2_XBARE__ENABLED;

  P1MDOUT |= P1MASK_B4__COMPARED;
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
  LED0 = 0;

  while (1) {}                             // Spin forever
}
