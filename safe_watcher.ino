#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

const char NORMAL_STATUS = 'O';
const char ERROR_STATUS = 'x';

const int TEMP_PIN = 7;
const int HUMIDITY_PIN = 6;
const int SMOKE_PIN = 8;

void setLiquidCrystal() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void setTempAndHumidity() {
  pinMode(TEMP_PIN, INPUT);
  pinMode(HUMIDITY_PIN, INPUT);
}

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
  char temp[4] = {'3', '5', 'C', ' '};
  char humidity[4] = {'1', '2', '%', ' '};
  
  lcd.setCursor(0, 1);
  lcd.print(analogRead(TEMP_PIN));
  lcd.print(analogRead(HUMIDITY_PIN));
//  lcd.print(temp);
//  lcd.setCursor(4, 1);
//  lcd.print(humidity);
 
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
}


void drawDistanceStatus() {
  char distance[3] = {'D', NORMAL_STATUS, ' '};
  
//  lcd.setCursor(14, 1);
//  lcd.print(distance); 
}

void setup() {
  setLiquidCrystal();
  setTempAndHumidity();
  
  drawDateTime();
//  drawTempAndHumidity();
  drawAirSafeStatus();
//  drawAirSmokeStatus();
  drawDistanceStatus();
}

void loop() {
  drawTempAndHumidity();
  drawAirSmokeStatus();
  delay(1000);
}


