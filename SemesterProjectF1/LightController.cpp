/*
 * File: LightController.cpp
 * Created: 16/05/2018 13.21.24
 * Author: Per Hogfeldt and Ebbe Helverskov
 */ 
#include <avr/io.h>
#include "LightController.h"

void LightController::setupTimer(int dutyCycle) {
	if (dutyCycle <= 100) {
		DDRB = 255; // Make PortB to output
		PORTB = 0; // set no signal out
		//Setup for Timer 1: Non inverted and phase correct PVM mode
		//					 10 bit and TOP = 1023 with no prescaler
		TCCR1A = 0b10000011;
		TCCR1B = 0b00000001;
		
		// Duty cycle = 17% => OCR1A = 173.91 (17% => 10 mA)
		OCR1A = (dutyCycle*1023)/100;
	}
}

void LightController::turnOnDrivingLight() {
		setupTimer(17);
		DDRE |= (1<<3); // Make PortE bit 3  to output
		PORTB = 0; // set no signal out
		//Setup for Timer 3: Non inverted and phase correct PVM mode
		//					 10 bit and TOP = 1023 with no prescaler
		TCCR3A = 0b10000011;
		TCCR3B = 0b00000001;
		
		// Duty cycle = 17% => OCR1A = 173.91 (17% => 10 mA)
		OCR3A = 1023; 
}

void LightController::turnOffDrivingLight() {
	setupTimer(0);
	OCR3A = 0; // turn of front light
}

void LightController::turnOnBreakLight() {
	setupTimer(100);
}

void LightController::turnOffBreakLight() {
	setupTimer(17);
}