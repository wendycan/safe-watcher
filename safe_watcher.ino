#include <LiquidCrystal.h>
#include "DHT11.h"


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

const char NORMAL_STATUS = 'O';
const char ERROR_STATUS = 'x';

const int SMOKE_PIN = A5;

void setAirSmoke() {
  pinMode(SMOKE_PIN, INPUT);
}

void drawDateTime() {
  char date[11] = {'2', '0', '1', '6', '-', '1', '2', '-', '0', '8', ' '};
  char time[6] = {'1', '1', ':', '2', '6', ' '};
  
  lcd.setCursor(0, 0);
  lcd.print(date);
  lcd.print(time);
}

void drawTempAndHumidity() {
  DHT11_Read();
  
  lcd.setCursor(0, 1);
  lcd.print(TEM_Buffer_Int);
  lcd.print("C");
  lcd.print(HUMI_Buffer_Int);
  lcd.print("%");
}

void drawAirSafeStatus() {
  char safe[3] = {'A', NORMAL_STATUS, ' '};
  
  lcd.setCursor(8, 1);
  lcd.print(safe);
}

void drawAirSmokeStatus() {
  char smoke[3] = {'S', NORMAL_STATUS, ' '};
  
  lcd.setCursor(11, 1);
  lcd.print(analogRead(SMOKE_PIN));

  Serial.println('S');
  Serial.println(analogRead(SMOKE_PIN));
}

void drawDistanceStatus() {
  char distance[3] = {'D', NORMAL_STATUS, ' '};
  
//  lcd.setCursor(14, 1);
//  lcd.print(distance); 
}

void setup() {
  // setup lcd
  lcd.begin(16, 2);
  Serial.begin(9600);

  // setup temp
  DHT11_Read();
  delay(2000);
}

void loop() {
  drawTempAndHumidity();
  drawDateTime();

  delay(500);
}

