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
		DDRA = 255;
		DDRH |= 255; // PORTH is now output
		TCCR4A = 0b11000001; // PVM 8-bit phase correct
		TCCR4B = 1;
		OCR4A = 256;
		speed_ = 0;
		setDriection(forward);
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
		PORTA &= ~(1);	
	} else if (direction == backward) {
		PORTA |= 1;
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
		OCR4A = 256;
		break;
	}
}

void Motor::breaks() {
	for (int a = speed_-1; a >= 0; a--) {
		setSpeed(a);
		run();
		_delay_ms(10.0);
	}
}