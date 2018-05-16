/*
 * File: main.cpp
 * Created: 16/05/2018 08.00.00
 * Author : Per Hogfeldt
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>		
#include <util/delay.h>
#include "LightController.h"

// Function declarations
bool test();
bool sensorTest();
bool motorTest();
bool lightTest();
bool audioTest();
bool carIntegration();

int main(void) {
	test();
    while (1) {} // Keep the MC running
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
	return false;
}

bool motorTest() {
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
	return false;
}

bool carIntegration() {
	return false;
}