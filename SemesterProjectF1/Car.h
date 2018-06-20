/**
 * File: Car.h
 * Created: 16/05/2018 08.14.38
 * Author: Per Hogfeldt
 */ 

#ifndef CAR_H_
#define CAR_H_

#include "AudioController.h"
#include "LightController.h"
#include "Motor.h"

/** 
 * Car is the central class, which purpose is to own the
 * classes representing the essential hardware for the 
 * car and define the control sequence in which their
 * features are called. 
 */
class Car{ 
public:

	/**
	 * Sets the driving speed and activate the motor
	 * Precondition: The car has been started
     * @param: Integer from 0-4, where 0 is the lowest speed and 4 is the highest
     * @return: void
     */	
	void drive(int);

	/**
	 * Starts the car by initiating car parts, turning on the light, play a start sound
	 * and set the car in motion
	 * Precondition: The car is placed in the starting area.
     * @param: none
     * @return: void
     */	
	void start();
	
	/**
	 * Activate the breaks, so that the car stops being in motion, turn of the car by turning 
	 * of the light and play a stop sound
	 * Precondition: The car is turned on
     * @param: none
     * @return: void
     */	
	void stop();
	
	/**
	 * Change motor direction to forward
	 * Precondition: The car is turned on
     * @param: none
     * @return: void
     */	
	void driveForward();
	
	/**
	 * Change motor direction to backward
	 * Precondition: The car is turned on
     * @param: none
     * @return: void
     */	
	void driveBackward();
	
	/**
	 * Stops the car from being in motion and activate break lights
	 * Precondition: The car is in motion
     * @param: none
     * @return: void
     */	
	void activateBreak();
	
	/**
	 * When a reflector has been passed by the car, the sensor will
	 * call this method to notify the Car. The Car will then increment
	 * its position and do whatever else is needed.
	 * Precondition: sensor is enabled
	 * @param: none
	 * @return: void	 
	 */
	void notified();
	
	/**
	 * Getter method for the reflector counter
	 * Precondition: The car has been started
	 * @param: none
	 * @return: An integer which is the number of reflectors which the car has passed
	 */	
	int getPosition();
	
private:
	// position stores the position of the car, where the int represents the
	// number of reflectors which the car has passed.
	int position_;
	// Carparts:
	AudioController audioController_;
	LightController lightController_;
	Motor motor_;
};
#endif /* CAR_H_ */