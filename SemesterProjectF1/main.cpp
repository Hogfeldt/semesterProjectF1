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
#include "modulTest.h"

// Function declarations
void driveAlgorithm();

Car g_car;
sensor g_sensor;
modulTest modulTest;

int main(void) {
	modulTest.audioTest();
    while (1) {} // Keep the MC running
}

void driveAlgorithm() {
	g_car.start();
	while(g_car.getPosition()<5){}
	g_car.activateBreak();
	g_car.driveBackward();
	g_car.drive(4);
	while(g_car.getPosition()<8){}
	g_car.activateBreak();
	g_car.driveForward();
	g_car.drive(4);
	while (g_car.getPosition()<10){}
	g_car.activateBreak();
	g_car.stop();
}
