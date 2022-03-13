#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal_I2C lcd(0x27,16,2); 


void setup() {

lcd.begin();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("  ARDUINO BASED       ");
lcd.setCursor(0,1);
lcd.print("  COIN SORTING       ");
delay(2000);
lcd.clear();
}

void loop() 
{
int f1=0,f2=0,f3=0;
int c1=0,c2=0,c3=0;
int s1=analogRead(A0);
int s2=analogRead(A1);
int s3=analogRead(A2);
lcd.setCursor(0,0);
lcd.print("CT10   EUR1   EUR2");

if(s1>=200 && f1==0)
{
  f1=1;
}
else if(s1<200 && f1==1)
{
  f1=0;
  c1++;
}

if(s2>=200 && f2==0)
{
  f2=1;
}
else if(s2<200 && f2==1)
{
  f2=0;
  c2++;
}

if(s3>=200 && f3==0)
{
  f3=1;
}
else if(s3<200 && f3==1)
{
  f3=0;
  c3++;
}
lcd.setCursor(1,1);
lcd.print(c1);
lcd.setCursor(7,1);
lcd.print(c2);
lcd.setCursor(14,1);
lcd.print(c3);
}
