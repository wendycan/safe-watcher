#include <LiquidCrystal.h>
#include "DHT11.h"


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

const char NORMAL_STATUS = 'O';
const char ERROR_STATUS = 'x';

const int SMOKE_PIN = A5;
const int DISTANCE_TRIG_PIN = 9;
const int DISTANCE_ECHO_PIN = 8;

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
  digitalWrite(DISTANCE_TRIG_PIN, LOW); //  低高低电平发一个短时间脉冲去 TrigPin
  delayMicroseconds(2);
  digitalWrite(DISTANCE_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(DISTANCE_TRIG_PIN, LOW);
  float distance = float( pulseIn(DISTANCE_ECHO_PIN, HIGH) * 17 ) / 100000; //  将回波时间换算成m

  lcd.setCursor(11, 1);
  lcd.print(distance); 
  lcd.print('m'); 
}

void setup() {
  // setup lcd
  lcd.begin(16, 2);
  Serial.begin(9600);

  // setup temp
  DHT11_Read();
  
  // setup distance
  pinMode(DISTANCE_TRIG_PIN, OUTPUT);
  pinMode(DISTANCE_ECHO_PIN, INPUT);
  
  delay(2000);
}

void loop() {
  drawTempAndHumidity();
  drawDateTime();
  drawDistanceStatus();
  delay(500);
}

