/*
 * File: Car.cpp
 * Created: 18/06/2018 11.28.49
 *  Author: Per Hogfeldt	
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Car.h"
#include "sensor.h"
#include "Motor.h"
#include "AudioController.h"
#include "globals.h"
#include "LightController.h"

void Car::start(){
	position_ = 0;
	audioController_.playStartSound();
	g_sensor.enableSensor();
	motor_.setSpeed(4);
	motor_.run();
	lightController_.turnOnDrivingLight();
}
	
void Car::stop(){
	motor_.breaks();
	motor_.stop();
	audioController_.playStopSound();
	_delay_ms(500);
	lightController_.turnOffDrivingLight();
}
	
void Car::driveForward() {
	motor_.setDriection(forward);
}
	
void Car::driveBackward() {
	motor_.setDriection(backward);
}
	
void Car::activateBreak() {
	lightController_.turnOnBreakLight();
	motor_.breaks();
	lightController_.turnOffBreakLight();
}

void Car::drive(int speed) {
	motor_.setSpeed(speed);
	motor_.run();
}
	
void Car::notified() {
	audioController_.playReflectSound();
	position_++;
}

int Car::getPosition() {
	return position_;
}
