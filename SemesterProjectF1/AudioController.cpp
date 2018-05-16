#include <SoftwareSerial.h>
int Rx_pin = 0;
int Tx_pin = 1;
SoftwareSerial Somo(Rx_pin,Tx_pin);
typedef struct _ControlMsg{ //struct holding the bytes to be transmitted
  char  start;
  char  cmd;
  char  feedback;
  char  para1;
  char  para2;
  char  checksum1;
  char  checksum2;
  char  end;
} ControlMsg;

AudioController::ControlMsg(){
  Somo.begin(9600); //baud rate 9600
}

void AudioController::playSound(char track){
  ControlMsg ctrlMsg;
  char cmd = 0x0F; //command:"Play a specified folder & track"
  char feedback = 0; //no feedback
  char para1 = 1; //first folder
  char para2 = track; //track number
  //populate struct
  ctrlMsg.start = 0x7E;
  ctrlMsg.cmd = cmd;
  ctrlMsg.feedback = feedback;
  ctrlMsg.para1 = para1;
  ctrlMsg.para2 = para2;
  //checksum (2 bytes) = 0xFFFF – (CMD + Feedback + Para1 + Para2) + 1
  short chksum = 0xFFFF - ((short)cmd + (short)feedback + (short)para1 + (short)para2) + 1;
  ctrlMsg.checksum1 = (char)(chksum >> 8); //first byte
  ctrlMsg.checksum2 = (char)chksum; //last byte
  ctrlMsg.end = 0xEF;
  Somo.write((const char*)&ctrlMsg, sizeof(ctrlMsg));
  Somo.flush();
}

void AudioController::playStartSound(){
  playSound(1, 1);
  // plays the first audio file in folder 1 on the SD card
}

void AudioController::playStopSound(){
	playSound(1, 2);
	// plays the second audio file in folder 1 on the SD card
}

void AudioController::playReflectSound(){
	playSound(1, 3);
	// plays the third audio file in folder 1 on the SD card
}