/*
 * Motor.cpp
 *
 * Created: 19-06-2018 11:06:06
 *  Author: jonas
 */ 

#include "Motor.h"

Motor :: Motor(){
		DDRA |= (1<<0);
		DDRH |= (1<<3);
		TCCR4A = 0000001;
		TCCR4B = 0;
		OCR4A = 256;
		speed_ = 0;
		direction_= forward
}

Motor :: setSpeed(int speed){
	speed_=speed;
}

Motor :: getSpeed(){
	return speed_
}

Motor :: stop(){
	setSpeed(0);
}

Motor :: setDriection(Direction){
	direction_=Direction;
}

Motor :: getDirection(){
	return direction_;
}


Motor :: run(){
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



