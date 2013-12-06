/*
 * sensor.c
 *
 *  Created on: Dec 3, 2013
 *      Author: C15Catherine.Baltar
 */


#include <msp430.h>
#include "sensor.h"

void lookLeft()
{
	  ADC10CTL0 &= ~ENC; 				// clear enable to change input pin
	  ADC10CTL1 = INCH_4;

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x2Fd)
	   P1DIR &= ~BIT0;                       // Clear P1.0 LED off
	 else
	   P1DIR |= BIT0;                        // Set P1.0 LED on

}

void lookRight()
{
	  ADC10CTL0 &= ~ENC; 				// clear enable to change input pin
	  ADC10CTL1 = INCH_7;                       // input A7

	 ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	 __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

	 if (ADC10MEM < 0x2fd)
	   P1DIR &= ~BIT6;                       // Clear P1.6 LED off
	 else
	   P1DIR |= BIT6;                        // Set P1.6 LED on
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

