#ifndef GUI_H_
#define GUI_H_

//======================Prototypes======================
void updateMenu();
void Home_screen();
bool menuInitalized = false;
bool backIsPressed = true; // By default home screen
bool RunMotor=true;
//======================================================
void Home_screen()
{
  
  lcd.clear();
 
  String Line1="F1> Filling Time";
  String Line2="F2> Waiting Time";
  String Line3="F3> Filling speed";
  String Line4="F4> Contact Us";
  
  lcd.setCursor(0,0);
  lcd.print(Line1);
  lcd.setCursor(0,1);
  lcd.print(Line2);
  lcd.setCursor(0,2);
  lcd.print(Line3);
  lcd.setCursor(0,3);
  lcd.print(Line4);
  
  menuInitalized=true;
  }
//======================================================
void updateMenu()
{ 
  char key = customKeypad.getKey();
  
    switch(key){
    case 'A':    
      if(backIsPressed){
        lcd.clear();
        fillingTime();
        backIsPressed=false;
      }
    break;
    
    case 'B':
      if(backIsPressed){
      lcd.clear();
      waitingTime();
      backIsPressed=false;
      }
    break;
        
    case 'C':
    if(backIsPressed){
      lcd.clear();
      fillingSpeed();
      backIsPressed=false;
    }
    break;
    
    case 'D':
    if(backIsPressed){
      lcd.clear();
      contactUs();
      backIsPressed=false;
    }
    break;
    
   case '#':
   if(RunMotor==true){
    RunMotor=false;
    runAuto_flag=false;
    //digitalWrite(LED_BUILTIN,LOW);
    analogWrite(Motor,0);
   }
   break;

   case '0':
    if(!backIsPressed){Home_screen();
    backIsPressed=true;
    }
   break;
    }
}
#endif
