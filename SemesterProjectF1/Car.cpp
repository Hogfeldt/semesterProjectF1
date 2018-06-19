/*
 * File: Car.cpp
 * Created: 18/06/2018 11.28.49
 *  Author: Per Hogfeldt	
 */ 

#include "Car.h"
#include "sensor.h"

Car::Car(){}


void Car::start(){
	position_ = 0;
	audioController_.playStartSound();
}
	
void Car::stop(){
	audioController_.playStopSound();
}
	
void Car::driveForward(int position) {}
	
void Car::driveBackward(int position) {}
	
void Car::breakDown() {}
	
void Car::notified() {
	//audioController_.playReflectSound();
	position_++;
}
