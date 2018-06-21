/*
 * Motor.cpp
 *
 * Created: 19-06-2018 11:06:06
 *  Author: jonas
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Motor.h"

Motor::Motor(){
		DDRA = 255; // PORTA is now output for the H-bidge (to change direction).
		DDRH |= 255; // PORTH is now output for PWM.
		TCCR4A = 0b11000001; // PVM 8-bit phase correct. TOP = 255.
		TCCR4B = 1; // no prescaler.
		OCR4A = 255; // 0% duty cycle. 
		speed_ = 0;// no speed.
		setDriection(forward); // Direction set.
}

void Motor::setSpeed(int speed){
	speed_=speed;
}

int Motor::getSpeed(){
	return speed_;
}

void Motor::stop(){
	setSpeed(0);
}

void Motor::setDriection(Direction direction){
	direction_= direction; 
	if(direction == forward) {
		PORTA &= ~(1);	// PORTA bit 0 = 0: forward. Controle the H-bridge.
	} else if (direction == backward) {
		PORTA |= 1; // PORT A bit 0 = 1: Backward. Controle the H-bridge.
	}
}

Direction Motor::getDirection(){
	return direction_;
}

void Motor::run(){
	switch (speed_){
	case 1:
		OCR4A = 153;
		break;
	case 2:
		OCR4A = 102;
		break;
	case 3: 
		OCR4A = 51;
		break;
	case 4:
		OCR4A = 0;
		break;
	default:
		OCR4A = 255; 
		break;
	}
}

void Motor::breaks() {
	for (int a = speed_-1; a >= 1; a--) {
		setSpeed(a);
		run();
		_delay_ms(500.0);
	}
}
