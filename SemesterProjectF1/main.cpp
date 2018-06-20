/*
 * File: main.cpp
 * Created: 16/05/2018 08.00.00
 * Author : Per Hogfeldt
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>		
#include <util/delay.h>
#include "LightController.h"
#include "sensor.h"
#include "Car.h"
#include "globals.h"
#include "Motor.h"
#include "AudioController.h"

// Function declarations
bool test();
bool sensorTest();
bool motorTest();
bool lightTest();
bool audioTest();
bool carIntegration();
void driveAlgorithm();

Car g_car;
sensor g_sensor;

int main(void) {
	driveAlgorithm();
    while (1) {} // Keep the MC running
}

void driveAlgorithm() {
	g_car.start();
	while(g_car.getPosition()<5){}
	g_car.breakDown();
	g_car.driveBackward();
	g_car.drive(4);
	while(g_car.getPosition()<8){}
	g_car.breakDown();
	g_car.driveForward();
	g_car.drive(4);
	while (g_car.getPosition()<10){}
	g_car.breakDown();
	g_car.stop();
}

bool test() {
	sensorTest();
	motorTest();
	lightTest();
	audioTest();
	carIntegration();
	return false;
}

bool sensorTest() {
	g_sensor.enableSensor();
	return true;
}

bool motorTest() {
	Motor testMotor;
	testMotor.setSpeed(4);
	testMotor.run();
	_delay_ms(3000);
	testMotor.breaks();
	//_delay_ms(1000);
	testMotor.setDriection(backward);
	_delay_ms(4000);
	testMotor.setSpeed(2);
	testMotor.run();
	_delay_ms(4000);
	testMotor.stop();
	return false;
}

bool lightTest() {
	LightController light;
	light.turnOnDrivingLight();
	_delay_ms(5000.0);
	light.turnOnBreakLight();
	_delay_ms(5000.0);
	light.turnOffBreakLight();
	_delay_ms(5000.0);
	light.turnOffDrivingLight();
	return false;
}

bool audioTest() {
	AudioController testAudio;
	testAudio.initSound();
	testAudio.playReflectSound();
	_delay_ms(2000);
	testAudio.playStartSound();
	_delay_ms(2000);
	testAudio.playStopSound();
	_delay_ms(2000);
	return true;
}

bool carIntegration() {
	return false;
}