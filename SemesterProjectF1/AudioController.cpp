#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
#include "AudioController.h"
extern "C" {
	#include "uart.h"
};

void AudioController::initSound() {
		InitUART(9600, 8, 'N');
		_delay_ms(100);
		SendChar(0x7E);
		SendChar(0x06);
		SendChar(0x00);
		SendChar(0x00);
		SendChar(0x1E);
		SendChar(0xFF);
		SendChar(0xDC);
		SendChar(0xEF);
		_delay_ms(100);
}

void AudioController::playSound(char track){
	char start = 0x7E;
	char cmd = 0x0F; //command:"Play a specified folder & track"
	char feedback = 1; //feedback
	char para1 = 1; //first folder
	char para2 = track; //track number
	//checksum (2 bytes) = 0xFFFF � (CMD + Feedback + Para1 + Para2) + 1
	short chksum = 0xFFFF - ((short)cmd + (short)feedback + (short)para1 + (short)para2) + 1;
	char checksum1 = (char)(chksum >> 8); //first byte
	char checksum2 = (char)chksum; //last byte
	char end = 0xEF;
	char comp[8] = {start, cmd, feedback, para1, para2, checksum1, checksum2, end};
	SendString(comp);
}

void AudioController::playStartSound(){
	playSound(1);
	// plays the first audio file in folder 1 on the SD card
}

void AudioController::playStopSound(){
	playSound(3);
	// plays the third audio file in folder 1 on the SD card
}

void AudioController::playReflectSound(){
	playSound(2);
	// plays the second audio file in folder 1 on the SD card
}