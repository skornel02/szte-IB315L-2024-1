// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>

enum {
  UNSENT,
  SENT
};

enum {
  UNREAD,
  READ
};

extern volatile uint8_t data_to_send;
extern volatile uint8_t data_to_send_status;

extern volatile uint8_t data_to_read;
extern volatile uint8_t data_to_read_status;

//-----------------------------------------------------------------------------
// UART0_ISR
//-----------------------------------------------------------------------------
//
// UART0 ISR Content goes here. Remember to clear flag bits:
// SCON0::RI (Receive Interrupt Flag)
// SCON0::TI (Transmit Interrupt Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (UART0_ISR, UART0_IRQn)
{
  if (SCON0_RI) {
      data_to_read = SBUF0;
      data_to_read_status = UNREAD;

      SCON0_RI = 0;
  }

  if (SCON0_TI) {
      SBUF0 = data_to_send;
      data_to_send_status = SENT;

      SCON0_TI = 0;
  }
}

