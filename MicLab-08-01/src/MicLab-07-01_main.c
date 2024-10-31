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

// Displays
enum
{
	LED_T1, LED_T2, LED_T3, LED_T4, LED_LEDS
};

#define DIGIT_COUNT 4
#define DIGITS 10

// Digits on display
enum
{
	DIGIT_0 = ~0x3f,
	DIGIT_1 = ~0x06,
	DIGIT_2 = ~0x5b,
	DIGIT_3 = ~0x4f,
	DIGIT_4 = ~0x66,
	DIGIT_5 = ~0x6D,
	DIGIT_6 = ~0x7D,
	DIGIT_7 = ~0x07,
	DIGIT_8 = ~0x7F,
	DIGIT_9 = ~0x6F,
};

uint8_t digit_values[DIGITS] = {
    DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4,
    DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9
};

// Ez egyszerre a számjegy és a kijelző.
uint8_t current_digit = LED_T1;

char digits[DIGIT_COUNT] = { 1, 2, 3, 4 };
//char digits[DIGIT_COUNT] = {5, 6, 7, 8};
//char digits[DIGIT_COUNT] = {0, 0, 9, 9};

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
// T4 shifted to T1 because... reasons.
static void select_display(uint8_t display)
{
	switch (display)
	{
	case LED_T1:
		DecoderA = 1;
		DecoderB = 1;
		DecoderC = 0;

		break;
	case LED_T2:
		DecoderA = 0;
		DecoderB = 0;
		DecoderC = 0;

		break;
	case LED_T3:
		DecoderA = 1;
		DecoderB = 0;
		DecoderC = 0;

		break;
	case LED_T4:
		DecoderA = 0;
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
}

// Ez lehetne egy valós decoder, de
// az eltárolt értékek gyorsabbak.
static uint8_t digit_decoder(char digit)
{
	if (digit >= DIGITS)
	{
		return 0;
	}

	return digit_values[digit];
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

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main(void)
{
	uint8_t digit;

	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();

	while (1)
	{
		// $[Generated Run-time code]
		// [Generated Run-time code]$

		if (TMR2CN0_TF2H)
		{
			// disable leds
			DispOutEnable = 1;

			select_display(current_digit);

			//write to spi
			digit = digit_decoder(digits[current_digit]);
			write_to_spi(digit);

			//send signal to bit shifter.
			DispOutEnable = 0;

			current_digit = (current_digit + 1) % DIGIT_COUNT;
			TMR2CN0_TF2H = 0;
		}
	}
}
