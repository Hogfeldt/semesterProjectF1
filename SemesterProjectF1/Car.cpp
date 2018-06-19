/*
 * File: Car.cpp
 * Created: 18/06/2018 11.28.49
 *  Author: Per Hogfeldt	
 */ 

#include "Car.h"
#include "sensor.h"
#include "Motor.h"
#include "AudioController.h"
#include "globals.h"

void Car::start(){
	position_ = 0;
	audioController_.playStartSound();
	g_sensor.enableSensor();
	motor_.setSpeed(1);
	motor_.run();
}
	
void Car::stop(){
	motor_.breaks();
	motor_.stop();
	audioController_.playStopSound();
}
	
void Car::driveForward() {}
	
void Car::driveBackward() {}
	
void Car::breakDown() {}
	
void Car::notified() {
	//audioController_.playReflectSound();
	position_++;
}

int Car::getPosition() {
	return position_;
}
