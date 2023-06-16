#ifndef Main_H_
#define Main_H_

  //Do not change the organization
  bool runAuto_flag=false;
  bool runManual_flag=false;
  
  #include "HAL.h"
  #include "LCD.h"
  #include "menu.h"
  #include "GUI.h"
  #include "Motor.h"
  //#include "SDcard.h"

//======================Prototypes======================
void init_main();
void runMain();
//======================================================
void init_main()
{
  Serial.begin(9600); 
  HAL_init();
  LCD_init();
  delay(1000);
  
  /*
  if (!SD.begin(chipSelect)) {
        Serial.println("Error 0");
        lcd.clear();
        lcd.setCursor(0,3);
        lcd.print("Error 0");
        while (1);
  }
  
  Variables_init();*/
  
  updateMenu();
  }
//======================================================
void runMain()
{
  if(!menuInitalized)Home_screen();
  updateMenu();
  runMotor();
  }
#endif
