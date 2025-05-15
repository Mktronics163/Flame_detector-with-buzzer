#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int flame = A0;
int Flame = 3;
int red = 5;
int green = 4;
int buzzer = 6;
int flam;
void  setup(){
  pinMode(A0,INPUT);
  pinMode(3,INPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Flame");
  lcd.setCursor(5,1);
  lcd.print("Detector");
  delay(3000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Created by");
  lcd.setCursor(3,1);
  lcd.print("MKTRONICS");
  delay(3000);
  lcd.clear();
}
void loop(){
 flam = digitalRead(3);
 if (flam == HIGH){
  lcd.setCursor(0,0);
  lcd.print("Flame detected");
  lcd.setCursor(1,1);
  lcd.print("Please evacuate!!!");
  delay(1000);
  tone(6,500,2000);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  delay(1000);
  digitalWrite(4,LOW);
 }else{
  lcd.setCursor(3,0);
  lcd.print("You're");
  lcd.setCursor(4,1);
  lcd.print("Safe");
  delay(1000);
  lcd.clear();
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  noTone(6);
 }
}
