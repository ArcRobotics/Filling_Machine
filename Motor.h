#ifndef Motor_H_
#define Motor_H_

#define Auto digitalRead(switchPin)==0
#define Manual digitalRead(pushPedal)==0
#define startIspress key=='*'


//======================Prototypes======================
void motorFilling();
void runMotor();
void autoMode();
void manualMode();
//======================Variables======================
unsigned long currTime=0;
bool runAuto_flag=false;
bool runManual_flag=false;
//======================================================
void runMotor()
{
    char key = customKeypad.getKey();
    if(startIspress && Auto){
      runAuto_flag=true;
      RunMotor=true;
      Filling.flag=true;
    }
    else if(Manual && !Auto)
    {
      runManual_flag=true;
    }
    
    if(runAuto_flag && RunMotor==true){  
        autoMode();//Turn on automatic with filling & wait time durations 
      }
     
    else if(runManual_flag){
        manualMode();//Turn on Manual with filling time duration 
      }
}
//======================================================
void autoMode()
{
 
 // Get current time in milliseconds
 currTime=millis();

 // Check if enough time has passed since last filling operation, and if filling is not already in progress
  if((((currTime-Filling.prevTime)/1000)>=(Filling.Time)) && Filling.flag==false)
  { 
    // Update time of last filling operation
    Filling.prevTime=currTime;
    
    // Update time of last waiting period
    wait.prevTime=currTime;
    
    // Turn off the motor using the motor speed
     //digitalWrite(LED_BUILTIN,LOW);
     analogWrite(Motor,0);

    // Set flag indicating filling operation in progress
    Filling.flag=true;
    }
    
  else if(((currTime-wait.prevTime)/1000)>=(wait.Time) && Filling.flag==true && RunMotor==true)
  {       

    // Update time of last filling operation
    Filling.prevTime=currTime;
    
    // Update time of last waiting period
    wait.prevTime=currTime;
    
    // Turn on the motor using the motor speed
    //digitalWrite(LED_BUILTIN,HIGH);
    analogWrite(Motor,Motor_speed);
    
    // Set flag indicating filling operation is complete
    Filling.flag=false;
    } 
}
//======================================================
void manualMode()
{
  currTime=millis();//Get time in ms
  
  //digitalWrite(LED_BUILTIN,HIGH);
  analogWrite(Motor,Motor_speed);
  
  if((((currTime-Filling.prevTime)/1000)>=(Filling.Time)))
  {  
    Filling.prevTime=currTime;
    //digitalWrite(LED_BUILTIN,LOW);
    analogWrite(Motor,0);
    runManual_flag=false;
    }
}
#endif
