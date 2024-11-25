#include <SI_EFM8BB1_Register_Enums.h>

#define WD_DISABLE_A 0xDE
#define WD_DISABLE_B 0xAD

#define LED0 P1_B4

void SiLabs_Startup (void)
{
  // Disable the watchdog here.

  // Erre nincs konstans az Enumsban.
  WDTCN = WD_DISABLE_A;
  WDTCN = WD_DISABLE_B;

  XBR2 |= XBR2_XBARE__ENABLED;

  P1MDOUT |= P1MASK_B4__COMPARED;
}

int main (void)
{
  LED0 = 0;

  while (1) {}
}
