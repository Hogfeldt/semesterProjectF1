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
	 * Constructor
	 */
	Car();

	/**
	 * Starts the car by turning on the light, play a start sound
	 * and set the car in motion
	 * Precondition: The car is placed in the starting area.
     * @param: none
     * @return: void
     */	
	void start();
	
	/**
	 * Turns of the car by turning of the light and play a stop sound
	 * Precondition: The car is turned on
     * @param: none
     * @return: void
     */	
	void stop();
	
	/**
	 * Drives the car forward until the sensor has detected n
	 * number of reflects
	 * Precondition: The car is turned on
     * @param: Takes a number of reflects which the car should 
			   drive past
     * @return: void
     */	
	void driveForward(int);
	
	/**
	 * Drives the car backward until the sensor has detected n
	 * number of reflects
	 * Precondition: The car is turned on
     * @param: Takes a number of reflects which the car should 
			   drive past
     * @return: void
     */	
	void driveBackward(int);
	
	/**
	 * Stops the car from being in motion
	 * Precondition: The car is in motion
     * @param: none
     * @return: void
     */	
	void breakDown();
	
	/**
	 * When a reflector has been passed by the car, the sensor will
	 * call this method to notify the Car. The Car will then increment
	 * its position and do whatever else is needed.
	 * Precondition: None
	 * @param: none
	 * @return: void	 
	 */
	void notified();
	
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