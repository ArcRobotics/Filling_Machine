#ifndef menu_H_
#define menu_H_

//======================Prototypes======================
void fillingTime();
void waitingTime();
void fillingSpeed();
void contactUs();
int Get_num();
float Get_number();
//======================Variables======================
/*float fillTime=0;
float waitTime=0;*/
float count=0;
float fillSpeed=0;
int Motor_speed=0;
//======================================================
int  Get_num()
{
  char key;
  int key_idc;
  do{
  key = customKeypad.getKey();
  key_idc=key-'0';//Change Char to int 
  }while(key_idc>9||key_idc<0);    //modify
  return key_idc;
  }
//======================================================
void fillingTime(){
  lcd.print("> Filling Time:");
  lcd.setCursor(5,2);
  lcd.print(Filling.Time);
  Filling.Time=0;
  Filling.Time=Get_number();
  lcd.clear();
  lcd.print("> Filling Time: ");
  lcd.setCursor(5,3);
  lcd.print(Filling.Time);
  delay(1500);
}
//======================================================
void waitingTime(){
  lcd.print("> Waiting Time:");
  lcd.setCursor(5,2);
  lcd.print(wait.Time);
  wait.Time=0;//Clear value for new one
  wait.Time=Get_number();
  lcd.clear();
  lcd.print("> Waiting Time: ");
  lcd.setCursor(5,3);
  lcd.print(wait.Time);
  delay(1500);
}
//======================================================
void fillingSpeed(){
  lcd.print("> Filling Speed:");
  lcd.setCursor(5,2);
  lcd.print(fillSpeed);
  fillSpeed=0;//Clear value for new one
  fillSpeed=Get_number();
  Motor_speed=(fillSpeed/100)*255;
  lcd.clear();
  lcd.print("> Filling Speed:");
  lcd.setCursor(5,2);
  lcd.print(fillSpeed);
  delay(1500);
}
//======================================================
void contactUs(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("> Contact us: ");
  lcd.setCursor(0, 1);
  lcd.print(" National Trade Co. ");
  lcd.setCursor(4, 3);
  lcd.print(" 01061204779");
  }
//======================================================
float Get_number()
{
  float Number=0;
  int mult=2;
    for(int j=0;j<5;j++){
      if(j<=2){
        Number+=Get_num()*pow(10,mult);
        mult--;
      }
      else if(j==3){
         Number+=float(Get_num())/10;
      }
      else if(j==4){
        Number+=float(Get_num())/100;
        if(Number==0){
          j=-1;//works Not sure why xD !!!!!
          mult=2;
          lcd.setCursor(0,3);
          lcd.print("Error 2");
          delay(3000);
          lcd.setCursor(0,3);
          lcd.print("                     ");
          lcd.setCursor(5,3);
          lcd.print("             ");
        }
      }
      lcd.setCursor(5,2);
      lcd.print(Number);
    } 
  return(Number);
  }
  
#endif
