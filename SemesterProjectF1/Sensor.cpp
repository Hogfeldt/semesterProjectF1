/*
 * File: Sensor.cpp
 * Created: 30/05/2018 13.55.48
 * Author: Per Hogfeldt
 */ 

 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include "sensor.h"
 #include "Car.h"
 #include "globals.h"
 
ISR(INT4_vect){
	PORTB ^= (1<<7);
	//g_sensor.notify();
	// Notify car
	//disable external interupt
	//start timer interupt
}
;
ISR(INT5_vect) {
	PORTB ^= (1<<6);
}

 
 void sensor::enableSensor() {
	DDRB = 0xFF;
	DDRE = 0; // Set Port E til input 
	EIMSK |= 0b00110000; // Enable Int4 and Int5;
	EICRB |= 0b00001111; // Int4 og Int5 trigges paa Rising Edge
	sei();
 }

 void sensor::notify() {
	g_car.notified();
 }