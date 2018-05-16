/*
 * SemesterProjectF1.cpp
 *
 * Created: 16/05/2018 08.00.00
 * Author : Per Hogfeldt
 */ 

#include <avr/io.h>

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
}

bool sensorTest() {
	return false;
}

bool motorTest() {
	return false;
}

bool lightTest() {
	return false;
}

bool audioTest() {
	return false;
}

bool carIntegration() {
	return false;
}
