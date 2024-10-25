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

#define ADC_RESOLUTION 1024.0f
#define REF_VOLTAGE_MV 3300u

// Displays
enum {
  LED_T1,
  LED_T2,
  LED_T3,
  LED_T4,
  LED_LEDS
};

#define DIGIT_COUNT 4
#define DIGITS 10

// Digits on display
enum {
  DIGIT_0 = 0x3f,
  DIGIT_1 = 0x06,
  DIGIT_2 = 0x5b,
  DIGIT_3 = 0x4f,
  DIGIT_4 = 0x66,
  DIGIT_5 = 0x6D,
  DIGIT_6 = 0x7D,
  DIGIT_7 = 0x07,
  DIGIT_8 = 0x7F,
  DIGIT_9 = 0x6F,
};

uint8_t digit_values[DIGITS] = {
    DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4,
    DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9
};

enum {
  PROGRAM_READING,
  PROGRAM_DISPLAYING,
};

// Ez egyszerre a számjegy és a kijelző.
uint8_t current_digit = LED_T1;

char digits[DIGIT_COUNT] = {1, 2, 3, 4};

uint8_t program_state = PROGRAM_READING;

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
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

// Enable selected display.
// Tudom hogy most overkill, de hasznos lehet még
void select_display(uint8_t display)
{
  switch (display) {
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
}

// Ez lehetne egy valós decoder, de
// az eltárolt értékek gyorsabbak.
uint8_t digit_decoder(char digit)
{
  if (digit >= DIGITS)
  {
    return 0;
  }

  return digit_values[digit];
}

void write_to_spi(uint8_t data_to_send) {
  SPI0CN0_SPIF = 0;
  SPI0DAT = data_to_send;

  // Wait until data is sent out
  while(!SPI0CN0_SPIF);

  SPI0CN0_SPIF = 1;
}

uint16_t read_adc(void) {
    ADC0CN0_ADINT = 0;
    ADC0CN0_ADBUSY = 1;
    while (!ADC0CN0_ADINT);

    return ADC0;
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();

  select_display(LED_LEDS);

  while (1) 
  {
    // $[Generated Run-time code]
    // [Generated Run-time code]$

    if (program_state == PROGRAM_READING)
    {
        uint16_t adc_value = read_adc();
        // Simplified (no approximation) voltage divider equation
        uint16_t voltage_mv = adc_value * (REF_VOLTAGE_MV / ADC_RESOLUTION);
        char digit;
        uint8_t i;

        for (i = 1; i <= DIGIT_COUNT; i++)
        {
            digit = adc_value % DIGITS;
            adc_value = adc_value / DIGITS;

            digits[DIGIT_COUNT - i] = digit;
        }
    }
    else if (program_state == PROGRAM_DISPLAYING)
    {
        if (!TMR2CN0_TF2H)
        {
            TMR2CN0_TF2H = 0;

            // disable leds
            DispOutEnable = 1;

            select_display(current_digit);

            //write to spi
            write_to_spi(digit_decoder(digits[current_digit]));

              //send signal to bit shifter.
            DispOutEnable = 0;

            current_digit = (current_digit + 1) % DIGIT_COUNT;

            // All digits were displayed
            if (current_digit == 0)
            {
                program_state = PROGRAM_READING;
            }
        }
    }
  }                             
}
