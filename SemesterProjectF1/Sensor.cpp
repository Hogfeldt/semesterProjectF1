/*
 * File: Sensor.cpp
 * Created: 30/05/2018 13.55.48
 * Author: Per Hogfeldt
 */ 

 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include "sensor.h"
 
ISR(INT4_vect){
	PORTB ^= (1<<7);
}
 
 void sensor::enableSensor() {
	DDRB = 0xFF;
	DDRE = 0; // Set Port E til input 
	EIMSK |= 0b00010000; // Enable Int4;
	EICRB |= 0b00000011; // Int4 trigges paa Rising Edge
	sei();
 }
 
 void sensor::notify() {
	 
 }