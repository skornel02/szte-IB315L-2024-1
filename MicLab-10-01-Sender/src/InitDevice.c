//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void
enter_DefaultMode_from_RESET (void)
{
  // $[Config Calls]
  WDT_0_enter_DefaultMode_from_RESET ();
  PORTS_0_enter_DefaultMode_from_RESET ();
  PBCFG_0_enter_DefaultMode_from_RESET ();
  CLOCK_0_enter_DefaultMode_from_RESET ();
  TIMER01_0_enter_DefaultMode_from_RESET ();
  TIMER_SETUP_0_enter_DefaultMode_from_RESET ();
  // [Config Calls]$

}

extern void
WDT_0_enter_DefaultMode_from_RESET (void)
{
  // $[Watchdog Timer Init Variable Declarations]
  uint32_t i;
  bool ea;
  // [Watchdog Timer Init Variable Declarations]$

  // $[WDTCN - Watchdog Timer Control]
  // Deprecated
  // [WDTCN - Watchdog Timer Control]$

  // $[WDTCN_2 - Watchdog Timer Control]

  // Feed WDT timer before disabling (Erratum WDT_E102)
  WDTCN = 0xA5;

  // Add 2 LFO cycle delay before disabling WDT (Erratum WDT_E102)
  for (i = 0; i < (2 * 3062500UL) / (10000 * 3); i++)
    {
      NOP ();
    }

  // Disable WDT
  ea = IE_EA;
  IE_EA = 0;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  IE_EA = ea;

  // [WDTCN_2 - Watchdog Timer Control]$

}

extern void
PBCFG_0_enter_DefaultMode_from_RESET (void)
{
  // $[XBR2 - Port I/O Crossbar 2]
  /***********************************************************************
   - Weak Pullups enabled 
   - Crossbar enabled
   ***********************************************************************/
  XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
  // [XBR2 - Port I/O Crossbar 2]$

  // $[PRTDRV - Port Drive Strength]
  // [PRTDRV - Port Drive Strength]$

  // $[XBR0 - Port I/O Crossbar 0]
  /***********************************************************************
   - UART TX, RX routed to Port pins P0.4 and P0.5
   - SPI I/O unavailable at Port pins
   - SMBus 0 I/O unavailable at Port pins
   - CP0 unavailable at Port pin
   - Asynchronous CP0 unavailable at Port pin
   - CP1 unavailable at Port pin
   - Asynchronous CP1 unavailable at Port pin
   - SYSCLK unavailable at Port pin
   ***********************************************************************/
  XBR0 = XBR0_URT0E__ENABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__DISABLED
      | XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
      | XBR0_CP1AE__DISABLED | XBR0_SYSCKE__DISABLED;
  // [XBR0 - Port I/O Crossbar 0]$

  // $[XBR1 - Port I/O Crossbar 1]
  // [XBR1 - Port I/O Crossbar 1]$

}

extern void
PORTS_0_enter_DefaultMode_from_RESET (void)
{
  // $[P0 - Port 0 Pin Latch]
  // [P0 - Port 0 Pin Latch]$

  // $[P0MDOUT - Port 0 Output Mode]
  /***********************************************************************
   - P0.0 output is open-drain
   - P0.1 output is open-drain
   - P0.2 output is open-drain
   - P0.3 output is open-drain
   - P0.4 output is push-pull
   - P0.5 output is open-drain
   - P0.6 output is open-drain
   - P0.7 output is open-drain
   ***********************************************************************/
  P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__OPEN_DRAIN
      | P0MDOUT_B2__OPEN_DRAIN | P0MDOUT_B3__OPEN_DRAIN | P0MDOUT_B4__PUSH_PULL
      | P0MDOUT_B5__OPEN_DRAIN | P0MDOUT_B6__OPEN_DRAIN
      | P0MDOUT_B7__OPEN_DRAIN;
  // [P0MDOUT - Port 0 Output Mode]$

  // $[P0MDIN - Port 0 Input Mode]
  // [P0MDIN - Port 0 Input Mode]$

  // $[P0SKIP - Port 0 Skip]
  // [P0SKIP - Port 0 Skip]$

  // $[P0MASK - Port 0 Mask]
  // [P0MASK - Port 0 Mask]$

  // $[P0MAT - Port 0 Match]
  // [P0MAT - Port 0 Match]$

}

extern void
TIMER01_0_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  //Save Timer Configuration
  uint8_t TCON_save;
  TCON_save = TCON;
  //Stop Timers
  TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

  // [Timer Initialization]$

  // $[TH0 - Timer 0 High Byte]
  // [TH0 - Timer 0 High Byte]$

  // $[TL0 - Timer 0 Low Byte]
  // [TL0 - Timer 0 Low Byte]$

  // $[TH1 - Timer 1 High Byte]
  /***********************************************************************
   - Timer 1 High Byte = 0x96
   ***********************************************************************/
  TH1 = (0x96 << TH1_TH1__SHIFT);
  // [TH1 - Timer 1 High Byte]$

  // $[TL1 - Timer 1 Low Byte]
  // [TL1 - Timer 1 Low Byte]$

  // $[Timer Restoration]
  //Restore Timer Configuration
  TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

  // [Timer Restoration]$

}

extern void
TIMER_SETUP_0_enter_DefaultMode_from_RESET (void)
{
  // $[CKCON0 - Clock Control 0]
  /***********************************************************************
   - System clock divided by 12
   - Counter/Timer 0 uses the clock defined by the prescale field, SCA
   - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 1 uses the system clock
   ***********************************************************************/
  CKCON0 = CKCON0_SCA__SYSCLK_DIV_12 | CKCON0_T0M__PRESCALE
      | CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
      | CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
      | CKCON0_T1M__SYSCLK;
  // [CKCON0 - Clock Control 0]$

  // $[TMOD - Timer 0/1 Mode]
  /***********************************************************************
   - Mode 0, 13-bit Counter/Timer
   - Mode 2, 8-bit Counter/Timer with Auto-Reload
   - Timer Mode
   - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
   - Timer Mode
   - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
   ***********************************************************************/
  TMOD = TMOD_T0M__MODE0 | TMOD_T1M__MODE2 | TMOD_CT0__TIMER
      | TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
  // [TMOD - Timer 0/1 Mode]$

  // $[TCON - Timer 0/1 Control]
  /***********************************************************************
   - Start Timer 1 running
   ***********************************************************************/
  TCON |= TCON_TR1__RUN;
  // [TCON - Timer 0/1 Control]$

}

extern void
CLOCK_0_enter_DefaultMode_from_RESET (void)
{
  // $[CLKSEL - Clock Select]
  /***********************************************************************
   - Clock derived from the Internal High-Frequency Oscillator
   - SYSCLK is equal to selected clock source divided by 1
   ***********************************************************************/
  CLKSEL = CLKSEL_CLKSL__HFOSC | CLKSEL_CLKDIV__SYSCLK_DIV_1;
  // [CLKSEL - Clock Select]$

}

