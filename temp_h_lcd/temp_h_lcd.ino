
#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x3F
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;
int DHTp = 7;
dht DHT;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
 lcd.begin (16,2); //  <<----- My LCD was 16x2
 lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 lcd.setBacklight(HIGH);
 lcd.home();

 lcd.print("temp & humidity");lcd.setCursor(0,1); 
 lcd.print("by Benjamin");
 delay(2000);
   
}

void loop()
{
  int chk = DHT.read11(DHTp);
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(DHT.temperature); lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("humidity: "); lcd.print(DHT.humidity); lcd.print("%");
  delay(1000);
}
