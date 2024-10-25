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

#define DICE_SIDES 6
#define PERGES_COUNT 250

// Displays
enum
{
	LED_T1, LED_T2, LED_T3, LED_T4, LED_LEDS
};

// Leds on display
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
	PRESSED, UNPRESSED,
};

uint8_t currentNumber = 0;

// szorgalmi pergés mentesítés
uint8_t lastPressStatus = UNPRESSED;
uint8_t pressCount = 0;
uint8_t buttonStatus = UNPRESSED;

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
	while (!SPI0CN0_SPIF)
		;

	SPI0CN0_SPIF = 1;
}

uint8_t get_data_from_number(uint8_t num)
{
	switch (num)
	{
	case 0:

		return ~(LED_7);
	case 1:

		return ~(LED_1 | LED_6);
	case 2:

		return ~(LED_1 | LED_7 | LED_6);
	case 3:

		return ~(LED_1 | LED_4 | LED_3 | LED_6);
	case 4:

		return ~(LED_1 | LED_4 | LED_3 | LED_6 | LED_7);
	case 5:

		return ~(LED_1 | LED_2 | LED_4 | LED_3 | LED_5 | LED_6);
	default:
		return ~0;
	}
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main(void)
{
	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();

	// Shift register beállítása
	// Decoder beállítása
	select_display(LED_LEDS);

	// set with invalid
	write_to_spi(get_data_from_number(111));

	while (1)
	{
		// $[Generated Run-time code]
		// [Generated Run-time code]$

		//
		if (!SW1)
		{
			if (lastPressStatus == UNPRESSED)
			{
				lastPressStatus = PRESSED;
				pressCount = 0;
			}
			else
			{
				if (pressCount < PERGES_COUNT)
				{
					++pressCount;
				}
				else
				{
					buttonStatus = PRESSED;

					// Hide number when pressing
					DispOutEnable = 1;
				}
			}
		}
		else
		{
			if (lastPressStatus == PRESSED)
			{
				lastPressStatus = UNPRESSED;
				pressCount = 0;
			}
			else
			{
				if (pressCount < PERGES_COUNT)
				{
					++pressCount;
				}
				else
				{
					buttonStatus = UNPRESSED;

					// Show number when released
					DispOutEnable = 0;
				}
			}
		}

		if (buttonStatus == PRESSED)
		{
			//write to spit
			write_to_spi(get_data_from_number(currentNumber));

			// increment data
			currentNumber = (currentNumber + 1) % DICE_SIDES;
		}
	}
}
