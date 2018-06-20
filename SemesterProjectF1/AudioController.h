/*
 * File: AudioController.h
 * Created: 16/05/2018 09.49.56
 * Author: Per Hoegfeldt
 */ 

#ifndef AUDIOCONTROLLER_H_
#define AUDIOCONTROLLER_H_
/**
 * AudioController is responsible for controlling the SOMO-II mp3
 */
class AudioController{
public:

	void initSound();
	
	/**
	 * Play the start sound
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void playStartSound();
	
	/**
	 * Play the stop sound
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void playStopSound();
	
	/**
	 * Play the reflect sound
	 * Precondition: none
     * @param: none
     * @return: void
     */	
	void playReflectSound();
	
private:
    /**
     * Plays an audio file from the SD card.
     * Precondition: none
	 * @param: char folder, char track
	 * @return: void
	 */
	void playSound(char);
};
#endif /* AUDIOCONTROLLER_H_ */