/**
 * File: Car.h
 * Created: 16/05/2018 08.14.38
 * Author: Per Hogfeldt
 */ 

#ifndef CAR_H_
#define CAR_H_
/** 
 * Car is the central class, which purpose is to own the
 * classes representing the essential hardware for the 
 * car and define the control sequence in which their
 * features are called. 
 */
class { 
public:
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
	void break();
	
private:
	// position stores the position of the car, where the int represents the
	// last reflect which is has past.
	int position_;
};
#endif /* CAR_H_ */