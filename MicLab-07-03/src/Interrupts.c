// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>

enum {
  INCREMENT_HANDLED,
  INCREMENT_UNHANDLED,
};

extern volatile incrementHandleStatus;

//-----------------------------------------------------------------------------
// TIMER2_ISR
//-----------------------------------------------------------------------------
//
// TIMER2 ISR Content goes here. Remember to clear flag bits:
// TMR2CN0::TF2H (Timer # High Byte Overflow Flag)
// TMR2CN0::TF2L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
{
  TMR2CN0_TF2H = 0;

  incrementHandleStatus = INCREMENT_UNHANDLED;
}

