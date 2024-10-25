//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$

#define DispClock P0_B0
#define DispData P0_B2
#define DispOutEnable P0_B3

#define DecoderA P1_B1
#define DecoderB P1_B2
#define DecoderC P0_B4

#define SW1 P0_B1

#define LED_COUNT 7

enum
{
	LED_T1, LED_T2, LED_T3, LED_T4, LED_LEDS
};

enum
{
	LED_7 = 1,
	LED_1 = 2,
	LED_2 = 4,
	LED_3 = 8,
	LED_6 = 16,
	LED_5 = 32,
	LED_4 = 64,
};

enum
{
	BUTTON_PRESSED, BUTTON_RELEASED
};

enum
{
	DIRECITON_RIGHT, DIRECTION_LEFT,
};

enum
{
	INCREMENT_HANDLED, INCREMENT_UNHANDLED,
};

uint8_t currentNumber = 0;
uint8_t currentDirection = DIRECITON_RIGHT;
uint8_t currentButtonState = BUTTON_RELEASED;
volatile incrementHandleStatus = INCREMENT_HANDLED;

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup(void)
{
	// $[SiLabs Startup]
	// [SiLabs Startup]$
}

// Enable selected display.
// Tudom hogy most overkill, de hasznos lesz még kövi gyakon.
void select_display(uint8_t display)
{
	switch (display)
	{
	case LED_T1:
		DecoderA = 0;
		DecoderB = 0;
		DecoderC = 0;

		break;
	case LED_T2:
		DecoderA = 1;
		DecoderB = 0;
		DecoderC = 0;

		break;
	case LED_T3:
		DecoderA = 0;
		DecoderB = 1;
		DecoderC = 0;

		break;
	case LED_T4:
		DecoderA = 1;
		DecoderB = 1;
		DecoderC = 0;

		break;
	case LED_LEDS:
		DecoderA = 0;
		DecoderB = 0;
		DecoderC = 1;

		break;

	default:
		break;
	}

	DispOutEnable = 0;
}

void write_to_spi(uint8_t data_to_send)
{
	SPI0CN0_SPIF = 0;
	SPI0DAT = data_to_send;

	// Wait until data is sent out
	while (!SPI0CN0_SPIF);

	SPI0CN0_SPIF = 0;
}

uint8_t get_data_from_number(uint8_t num)
{
	switch (num)
	{
	case 0:

		return ~LED_1;
	case 1:

		return ~LED_2;
	case 2:

		return ~LED_3;
	case 3:

		return ~LED_4;
	case 4:

		return ~LED_5;
	case 5:

		return ~LED_6;
	case 6:

		return ~LED_7;
	default:
		return 0;
	}
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main(void)
{
	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();

	select_display(LED_LEDS);

	while (1)
	{
		// $[Generated Run-time code]
		// [Generated Run-time code]$

		DispOutEnable = 1;

		//write to spit
		write_to_spi(get_data_from_number(currentNumber));

		//send signal to bit shifter.
		DispOutEnable = 0;

		if (incrementHandleStatus == INCREMENT_UNHANDLED)
		{
			// increment data
			if (currentDirection == DIRECITON_RIGHT)
			{
				currentNumber = (currentNumber + 1) % LED_COUNT;
			}
			else
			{
				if (currentNumber == 0)
				{
					currentNumber = LED_COUNT;
				}

				currentNumber -= 1;
			}

			incrementHandleStatus = INCREMENT_HANDLED;
		}

		if (currentButtonState == BUTTON_PRESSED && SW1)
		{
			currentButtonState = BUTTON_RELEASED;
			currentDirection =
					currentDirection == DIRECITON_RIGHT ?
							DIRECTION_LEFT : DIRECITON_RIGHT;
		}

		if (currentButtonState == BUTTON_RELEASED && !SW1)
		{
			currentButtonState = BUTTON_PRESSED;
		}
	}
}
