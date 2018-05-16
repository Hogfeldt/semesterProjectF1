/*
 * File: LightController.h
 * Created: 16/05/2018 10.28.11
 * Author: Per Hogfeldt
 */ 

#ifndef LIGHTCONTROLLER_H_
#define LIGHTCONTROLLER_H_
/**
 * LightController is responsible for controlling 
 * the LED light on the car
 */
class LightController {
public:
	/**
	 * Turn on the front and back light
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void turnOnDrivingLight();
	
	/**
	 * Turn off the front and back light
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void turnOffDrivingLight();
	
	/**
	 * The backlight should light brighter
	 * Precondition: Driving light is on
     * @param: none
     * @return: void
     */	
	void turnOnBreakLight();
	
	/**
	 * The back light should light normally
	 * Precondition: Driving light is on
     * @param: none
     * @return: void
     */	
	void turnOffBreakLight();
	
private: 
	void setupTimer(int);
};
#endif /* LIGHTCONTROLLER_H_ */