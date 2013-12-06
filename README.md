# Lab 7 Sensors

## Functions

- `void lookLeft();`
	- This function takes input from the left sensor and uses it to turn on the LED at P1.0.  The input from the sensor goes to A4. 
- `void lookRight();`
	- This function is the same as lookLeft for the right sensor.  It lights up P1.6 and uses A7.

## Example

```c
#include <msp430.h>
#include "sensor.h"

/*
 * main.c
 */
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
  ADC10CTL1 = INCH_4;                       // input A4
  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
  ADC10CTL1 |= ADC10DIV1|ADC10DIV0|ADC10DIV2;
                              // Set P1.0 to output direction

  while(1)
  {
    lookLeft();

    lookRight();
  }

    return 0;
}
```
