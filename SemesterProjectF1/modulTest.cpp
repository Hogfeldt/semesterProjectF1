/*
 * File: modulTest.cpp
 * Created: 20/06/2018 11.51.37
 * Author: Per Hogfeldt
 */ 
#define F_CPU 16000000UL
#include "modulTest.h"
#include "globals.h"
#include "Motor.h"
#include "sensor.h"
#include "AudioController.h"
#include "LightController.h"
#include "Car.h"
#include <util/delay.h>

void modulTest::test() {
	sensorTest();
	motorTest();
	lightTest();
	audioTest();
}

void modulTest::sensorTest() {
	g_sensor.enableSensor();
}

void modulTest::motorTest() {
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
}

void modulTest::lightTest() {
	LightController light;
	light.turnOnDrivingLight();
	_delay_ms(5000.0);
	light.turnOnBreakLight();
	_delay_ms(5000.0);
	light.turnOffBreakLight();
	_delay_ms(5000.0);
	light.turnOffDrivingLight();
}

void modulTest::audioTest() {
	AudioController testAudio;
	testAudio.initSound();
	testAudio.playReflectSound();
	_delay_ms(5000);
	testAudio.playStartSound();
	_delay_ms(5000);
	testAudio.playStopSound();
	_delay_ms(5000);
}