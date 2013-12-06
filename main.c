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

