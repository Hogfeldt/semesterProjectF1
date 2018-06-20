/*
 * File: Sensor.cpp
 * Created: 30/05/2018 13.55.48
 * Author: Per Hogfeldt and Ebbe Helverskov
 */ 

 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include "sensor.h"
 #include "Car.h"
 #include "globals.h"
 
ISR(INT4_vect){
	PORTB ^= (1<<7);
	g_sensor.notify(); // notify car
	EIMSK = 0; // Disable Int4 and Int5;
	//start timer interrupt
	TCCR5A |= 0b00000000;
	TCCR5B |= 0b00000101;
	TCNT5 = 65535-7811;
	TIMSK5 |= 1; // Enable overflow interrupt
}

ISR(INT5_vect) {
	PORTB ^= (1<<6);
	g_sensor.notify(); // Notify car
	EIMSK = 0; // Disable Int4 and Int5;
	//start timer interrupt
	TCCR5A |= 0b00000000;
	TCCR5B |= 0b00000101;
	TCNT5 = 65535-7811;
	TIMSK5 |= 1; // Enable overflow interrupt
}

ISR(TIMER5_OVF_vect) {
	//PORTB ^= (1<<5);
	TIMSK5 = 0;
	TCCR5B = 0;
	EIFR = 0b00110000; // Clear interrupt flags
	EIMSK |= 0b00110000; // Enable Int4 and Int5;
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
