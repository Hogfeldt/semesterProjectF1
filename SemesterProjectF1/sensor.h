/*
 * File: sensor.h
 * Created: 16/05/2018 11.49.25
 * Author: Per Hogfeldt
 */ 

#ifndef SENSOR_H_
#define SENSOR_H_
 class sensor {

 public:
	/**
	 * Initialize the sensors
	 * Precondition: none
	 * @param: none
	 * @return: void
	 */
	void enableSensor();
	
	/**
	 * When an interrupt from the sensors, either INT4 or INT3, the
	 * Sensor class notifies the Car class, that a reflector has been
	 * sensed.
	 * Precondition: enableSensor() has been called
	 * @param: none
	 * @return: none
	 */	
	void notify();
 };
#endif /* SENSOR_H_*/