#ifndef HAL_H_
#define HAL_H_

#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

byte rowPins[ROWS] = {9, 5, 6, 7}; 
byte colPins[COLS] = {8, 4, 3, 2}; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 




#define MakeOuput(s) pinMode(s,OUTPUT);
#define Motor 10
#define switchPin  A3
#define pushPedal  A2
#define chipSelect  A1

//======================================================
class variables{

  public:

  double prevTime;
  double  Time;
  bool   flag=false;
  //unsigned long currTime=0;
  double Start=0;
  double Stop=0;
}Filling,wait;
//======================================================
void HAL_init()
{
  //pinMode('#11',INPUT_PULLUP);
  pinMode(Motor,OUTPUT);
  //pinMode(LED_BUILTIN,OUTPUT);
  pinMode(switchPin, INPUT); 
  pinMode(pushPedal, INPUT); 
  customKeypad.begin( makeKeymap(hexaKeys) );
  }

#endif
