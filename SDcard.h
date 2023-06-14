#ifndef SDcard_H_
#define SDcard_H_

#include <SPI.h> // SD card & FAT filesystem library
#include <SD.h>

Sd2Card card;
File dataFile;


void Variables_init();
void Write_to_file();

void Variables_init(){

  char File_Name[15]="main.txt";
  String cmd;
  String subString;
  uint16_t variable_index;
  //Make sure the file exist
 if (SD.exists(File_Name)) ;
 else{
  Serial.println("Error 3");
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print("Error 3");
    while (1);
  }

  dataFile = SD.open(File_Name, FILE_READ); //open the file
  //available_data = dataFile.available();

  /*
   * Variables decleration shoud be like this
   * FillingTime=5
   * The space seperation between the variable and the number is paramount
  */
  while ( dataFile.available() > 0 ) {   
  cmd = dataFile.readStringUntil('\n');
  if(cmd.startsWith("FillingTime"))
  {
      variable_index = cmd.indexOf('=')+1;
      subString=cmd.substring(variable_index);
      Filling.Time=subString.toFloat();
     Serial.println(Filling.Time);
    }
  else if(cmd.startsWith("WaitingTime"))
  {
      variable_index = cmd.indexOf('=')+1;
      subString=cmd.substring(variable_index);
      wait.Time=subString.toFloat();
      Serial.println(wait.Time);
    }
 else if(cmd.startsWith("FillingSpeed"))
  {
      variable_index = cmd.indexOf('=')+1;
      subString=cmd.substring(variable_index);
      fillSpeed=subString.toInt();
      Serial.println(fillSpeed);
    }
  }
}
#endif
