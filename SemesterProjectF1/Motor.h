/*
 * File: Motor.h
 * Created: 16/05/2018 11.05.52
 * Author: Per Hogfeldt
 */ 

#ifndef MOTOR_H_
#define MOTOR_H_

// Including enum 'direction' for controlling the
// direction of the motor
#include "direction.h" 

/**
 * Motor is a class responsible for controlling the
 * cars motor and how it should function
 */
class Motor {
public:
	/** 
	*constructor
	**/
	Motor();
	
	/**
	 * Turn on the motor with the speed defined in attribute speed_
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void run();
	  
	/**
	 * Turn off the motor
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void stop();
	
	/**
	 * Step down the motor speed until the speed is 0
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void breaks();
	
	/**
	 * Getter for the attribute direction_
	 * Precondition: none
     * @param: none
     * @return: int
     */	
	int getSpeed();
	
	/**
	 * Mutator for the attribute speed_
	 * Precondition: none
     * @param: int
     * @return: void
     */	
	void setSpeed(int);
	
	/**
	 * Mutator for the attribute direction_
	 * Precondition: none
     * @param: direction
     * @return: void
     */	
	void setDriection(Direction);
	
	/**
	 * Getter for the attribute direction_
	 * Precondition: none
     * @param: none
     * @return: direction
     */	
	Direction getDirection();
	
private:
	Direction direction_; // Motor direction
	int speed_; // Motor speed
};
#endif /* MOTOR_H_ */