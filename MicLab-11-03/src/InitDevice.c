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
  PORTS_1_enter_DefaultMode_from_RESET ();
  PBCFG_0_enter_DefaultMode_from_RESET ();
  ADC_0_enter_DefaultMode_from_RESET ();
  VREF_0_enter_DefaultMode_from_RESET ();
  TIMER16_2_enter_DefaultMode_from_RESET ();
  PCA_0_enter_DefaultMode_from_RESET ();
  PCACH_0_enter_DefaultMode_from_RESET ();
  INTERRUPT_0_enter_DefaultMode_from_RESET ();
  // [Config Calls]$

}

extern void
PORTS_0_enter_DefaultMode_from_RESET (void)
{
  // $[P0 - Port 0 Pin Latch]
  // [P0 - Port 0 Pin Latch]$

  // $[P0MDOUT - Port 0 Output Mode]
  // [P0MDOUT - Port 0 Output Mode]$

  // $[P0MDIN - Port 0 Input Mode]
  // [P0MDIN - Port 0 Input Mode]$

  // $[P0SKIP - Port 0 Skip]
  /***********************************************************************
   - P0.0 pin is skipped by the crossbar
   - P0.1 pin is skipped by the crossbar
   - P0.2 pin is skipped by the crossbar
   - P0.3 pin is skipped by the crossbar
   - P0.4 pin is skipped by the crossbar
   - P0.5 pin is skipped by the crossbar
   - P0.6 pin is skipped by the crossbar
   - P0.7 pin is skipped by the crossbar
   ***********************************************************************/
  P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__SKIPPED | P0SKIP_B2__SKIPPED
      | P0SKIP_B3__SKIPPED | P0SKIP_B4__SKIPPED | P0SKIP_B5__SKIPPED
      | P0SKIP_B6__SKIPPED | P0SKIP_B7__SKIPPED;
  // [P0SKIP - Port 0 Skip]$

  // $[P0MASK - Port 0 Mask]
  // [P0MASK - Port 0 Mask]$

  // $[P0MAT - Port 0 Match]
  // [P0MAT - Port 0 Match]$

}

extern void
PORTS_1_enter_DefaultMode_from_RESET (void)
{
  // $[P1 - Port 1 Pin Latch]
  // [P1 - Port 1 Pin Latch]$

  // $[P1MDOUT - Port 1 Output Mode]
  // [P1MDOUT - Port 1 Output Mode]$

  // $[P1MDIN - Port 1 Input Mode]
  /***********************************************************************
   - P1.0 pin is configured for digital mode
   - P1.1 pin is configured for digital mode
   - P1.2 pin is configured for digital mode
   - P1.3 pin is configured for analog mode
   - P1.4 pin is configured for digital mode
   - P1.5 pin is configured for digital mode
   - P1.6 pin is configured for digital mode
   - P1.7 pin is configured for digital mode
   ***********************************************************************/
  P1MDIN = P1MDIN_B0__DIGITAL | P1MDIN_B1__DIGITAL | P1MDIN_B2__DIGITAL
      | P1MDIN_B3__ANALOG | P1MDIN_B4__DIGITAL | P1MDIN_B5__DIGITAL
      | P1MDIN_B6__DIGITAL | P1MDIN_B7__DIGITAL;
  // [P1MDIN - Port 1 Input Mode]$

  // $[P1SKIP - Port 1 Skip]
  /***********************************************************************
   - P1.0 pin is skipped by the crossbar
   - P1.1 pin is skipped by the crossbar
   - P1.2 pin is skipped by the crossbar
   - P1.3 pin is skipped by the crossbar
   - P1.4 pin is not skipped by the crossbar
   - P1.5 pin is not skipped by the crossbar
   - P1.6 pin is not skipped by the crossbar
   - P1.7 pin is not skipped by the crossbar
   ***********************************************************************/
  P1SKIP = P1SKIP_B0__SKIPPED | P1SKIP_B1__SKIPPED | P1SKIP_B2__SKIPPED
      | P1SKIP_B3__SKIPPED | P1SKIP_B4__NOT_SKIPPED | P1SKIP_B5__NOT_SKIPPED
      | P1SKIP_B6__NOT_SKIPPED | P1SKIP_B7__NOT_SKIPPED;
  // [P1SKIP - Port 1 Skip]$

  // $[P1MASK - Port 1 Mask]
  // [P1MASK - Port 1 Mask]$

  // $[P1MAT - Port 1 Match]
  // [P1MAT - Port 1 Match]$

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
  // [XBR0 - Port I/O Crossbar 0]$

  // $[XBR1 - Port I/O Crossbar 1]
  /***********************************************************************
   - CEX0 routed to Port pin
   - ECI unavailable at Port pin
   - T0 unavailable at Port pin
   - T1 unavailable at Port pin
   - T2 unavailable at Port pin
   ***********************************************************************/
  XBR1 = XBR1_PCA0ME__CEX0 | XBR1_ECIE__DISABLED | XBR1_T0E__DISABLED
      | XBR1_T1E__DISABLED | XBR1_T2E__DISABLED;
  // [XBR1 - Port I/O Crossbar 1]$

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
ADC_0_enter_DefaultMode_from_RESET (void)
{
  // $[ADC0CN1 - ADC0 Control 1]
  // [ADC0CN1 - ADC0 Control 1]$

  // $[ADC0MX - ADC0 Multiplexer Selection]
  /***********************************************************************
   - Select ADC0.11
   ***********************************************************************/
  ADC0MX = ADC0MX_ADC0MX__ADC0P11;
  // [ADC0MX - ADC0 Multiplexer Selection]$

  // $[ADC0CF - ADC0 Configuration]
  /***********************************************************************
   - SAR Clock Divider = 0x1F
   - ADC0 operates in 8-bit mode
   - The on-chip PGA gain is 1
   - Normal Track Mode
   ***********************************************************************/
  ADC0CF = (0x1F << ADC0CF_ADSC__SHIFT) | ADC0CF_AD8BE__8_BIT
      | ADC0CF_ADGN__GAIN_1 | ADC0CF_ADTM__TRACK_NORMAL;
  // [ADC0CF - ADC0 Configuration]$

  // $[ADC0AC - ADC0 Accumulator Configuration]
  /***********************************************************************
   - Left justified. No shifting applied
   - Disable 12-bit mode
   - ADC0H:ADC0L contain the result of the latest conversion when Burst
   Mode is disabled
   - Perform and Accumulate 1 conversion 
   ***********************************************************************/
  ADC0AC = ADC0AC_ADSJST__LEFT_NO_SHIFT | ADC0AC_AD12BE__12_BIT_DISABLED
      | ADC0AC_ADAE__ACC_DISABLED | ADC0AC_ADRPT__ACC_1;
  // [ADC0AC - ADC0 Accumulator Configuration]$

  // $[ADC0TK - ADC0 Burst Mode Track Time]
  // [ADC0TK - ADC0 Burst Mode Track Time]$

  // $[ADC0PWR - ADC0 Power Control]
  // [ADC0PWR - ADC0 Power Control]$

  // $[ADC0GTH - ADC0 Greater-Than High Byte]
  // [ADC0GTH - ADC0 Greater-Than High Byte]$

  // $[ADC0GTL - ADC0 Greater-Than Low Byte]
  // [ADC0GTL - ADC0 Greater-Than Low Byte]$

  // $[ADC0LTH - ADC0 Less-Than High Byte]
  // [ADC0LTH - ADC0 Less-Than High Byte]$

  // $[ADC0LTL - ADC0 Less-Than Low Byte]
  // [ADC0LTL - ADC0 Less-Than Low Byte]$

  // $[ADC0CN0 - ADC0 Control 0]
  /***********************************************************************
   - Enable ADC0 
   - ADC0 conversion initiated on overflow of Timer 2
   ***********************************************************************/
  ADC0CN0 &= ~ADC0CN0_ADCM__FMASK;
  ADC0CN0 |= ADC0CN0_ADEN__ENABLED | ADC0CN0_ADCM__TIMER2;
  // [ADC0CN0 - ADC0 Control 0]$

}

extern void
VREF_0_enter_DefaultMode_from_RESET (void)
{
  // $[REF0CN - Voltage Reference Control]
  /***********************************************************************
   - Disable the Temperature Sensor
   - The ADC0 ground reference is the GND pin
   - The internal reference operates at 1.65 V nominal
   - The ADC0 voltage reference is the VDD pin
   ***********************************************************************/
  REF0CN = REF0CN_TEMPE__TEMP_DISABLED | REF0CN_GNDSL__GND_PIN
      | REF0CN_IREFLVL__1P65 | REF0CN_REFSL__VDD_PIN;
  // [REF0CN - Voltage Reference Control]$

}

extern void
TIMER16_2_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  // Save Timer Configuration
  uint8_t TMR2CN0_TR2_save;
  TMR2CN0_TR2_save = TMR2CN0 & TMR2CN0_TR2__BMASK;
  // Stop Timer
  TMR2CN0 &= ~(TMR2CN0_TR2__BMASK);
  // [Timer Initialization]$

  // $[TMR2CN0 - Timer 2 Control]
  // [TMR2CN0 - Timer 2 Control]$

  // $[TMR2H - Timer 2 High Byte]
  // [TMR2H - Timer 2 High Byte]$

  // $[TMR2L - Timer 2 Low Byte]
  // [TMR2L - Timer 2 Low Byte]$

  // $[TMR2RLH - Timer 2 Reload High Byte]
  /***********************************************************************
   - Timer 2 Reload High Byte = 0x06
   ***********************************************************************/
  TMR2RLH = (0x06 << TMR2RLH_TMR2RLH__SHIFT);
  // [TMR2RLH - Timer 2 Reload High Byte]$

  // $[TMR2RLL - Timer 2 Reload Low Byte]
  /***********************************************************************
   - Timer 2 Reload Low Byte = 0xC6
   ***********************************************************************/
  TMR2RLL = (0xC6 << TMR2RLL_TMR2RLL__SHIFT);
  // [TMR2RLL - Timer 2 Reload Low Byte]$

  // $[TMR2CN0]
  /***********************************************************************
   - Start Timer 2 running
   ***********************************************************************/
  TMR2CN0 |= TMR2CN0_TR2__RUN;
  // [TMR2CN0]$

  // $[Timer Restoration]
  // Restore Timer Configuration
  TMR2CN0 |= TMR2CN0_TR2_save;
  // [Timer Restoration]$

}

extern void
INTERRUPT_0_enter_DefaultMode_from_RESET (void)
{
  // $[EIE1 - Extended Interrupt Enable 1]
  /***********************************************************************
   - Enable interrupt requests generated by the ADINT flag
   - Disable ADC0 Window Comparison interrupt
   - Disable CP0 interrupts
   - Disable CP1 interrupts
   - Disable all Port Match interrupts
   - Disable all PCA0 interrupts
   - Disable all SMB0 interrupts
   - Disable Timer 3 interrupts
   ***********************************************************************/
  EIE1 = EIE1_EADC0__ENABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
      | EIE1_ECP1__DISABLED | EIE1_EMAT__DISABLED | EIE1_EPCA0__DISABLED
      | EIE1_ESMB0__DISABLED | EIE1_ET3__DISABLED;
  // [EIE1 - Extended Interrupt Enable 1]$

  // $[EIP1 - Extended Interrupt Priority 1]
  // [EIP1 - Extended Interrupt Priority 1]$

  // $[IE - Interrupt Enable]
  /***********************************************************************
   - Enable each interrupt according to its individual mask setting
   - Disable external interrupt 0
   - Disable external interrupt 1
   - Disable all SPI0 interrupts
   - Disable all Timer 0 interrupt
   - Disable all Timer 1 interrupt
   - Disable Timer 2 interrupt
   - Disable UART0 interrupt
   ***********************************************************************/
  IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED | IE_ESPI0__DISABLED
      | IE_ET0__DISABLED | IE_ET1__DISABLED | IE_ET2__DISABLED
      | IE_ES0__DISABLED;
  // [IE - Interrupt Enable]$

  // $[IP - Interrupt Priority]
  // [IP - Interrupt Priority]$

}

extern void
PCA_0_enter_DefaultMode_from_RESET (void)
{
  // $[PCA Off]
  PCA0CN0_CR = PCA0CN0_CR__STOP;
  // [PCA Off]$

  // $[PCA0MD - PCA Mode]
  // [PCA0MD - PCA Mode]$

  // $[PCA0CENT - PCA Center Alignment Enable]
  // [PCA0CENT - PCA Center Alignment Enable]$

  // $[PCA0CLR - PCA Comparator Clear Control]
  // [PCA0CLR - PCA Comparator Clear Control]$

  // $[PCA0L - PCA Counter/Timer Low Byte]
  // [PCA0L - PCA Counter/Timer Low Byte]$

  // $[PCA0H - PCA Counter/Timer High Byte]
  // [PCA0H - PCA Counter/Timer High Byte]$

  // $[PCA0POL - PCA Output Polarity]
  // [PCA0POL - PCA Output Polarity]$

  // $[PCA0PWM - PCA PWM Configuration]
  // [PCA0PWM - PCA PWM Configuration]$

  // $[PCA On]
  PCA0CN0_CR = PCA0CN0_CR__RUN;
  // [PCA On]$

}

extern void
PCACH_0_enter_DefaultMode_from_RESET (void)
{
  // $[PCA0 Settings Save]
  // Select Capture/Compare register)
  PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
  // [PCA0 Settings Save]$

  // $[PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]
  /***********************************************************************
   - Disable negative edge capture
   - Disable CCF0 interrupts
   - Disable match function
   - 8 to 11-bit PWM selected
   - Disable positive edge capture
   - Enable comparator function
   - Enable PWM function
   - Disable toggle function
   ***********************************************************************/
  PCA0CPM0 = PCA0CPM0_CAPN__DISABLED | PCA0CPM0_ECCF__DISABLED
      | PCA0CPM0_MAT__DISABLED | PCA0CPM0_PWM16__8_BIT | PCA0CPM0_CAPP__DISABLED
      | PCA0CPM0_ECOM__ENABLED | PCA0CPM0_PWM__ENABLED | PCA0CPM0_TOG__DISABLED;
  // [PCA0CPM0 - PCA Channel 0 Capture/Compare Mode]$

  // $[PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]
  /***********************************************************************
   - PCA Channel 0 Capture Module Low Byte = 0xFF
   ***********************************************************************/
  PCA0CPL0 = (0xFF << PCA0CPL0_PCA0CPL0__SHIFT);
  // [PCA0CPL0 - PCA Channel 0 Capture Module Low Byte]$

  // $[PCA0CPH0 - PCA Channel 0 Capture Module High Byte]
  /***********************************************************************
   - PCA Channel 0 Capture Module High Byte = 0xFF
   ***********************************************************************/
  PCA0CPH0 = (0xFF << PCA0CPH0_PCA0CPH0__SHIFT);
  // [PCA0CPH0 - PCA Channel 0 Capture Module High Byte]$

  // $[Auto-reload]
  // [Auto-reload]$

  // $[PCA0 Settings Restore]
  // [PCA0 Settings Restore]$

}

