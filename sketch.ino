#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,4);
int Buzzer = 2;
byte dauGach[] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};
byte doC[] = {
  B11100,
  B10100,
  B11100,
  B01111,
  B01000,
  B01000,
  B01000,
  B01111
};
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, dauGach);
  lcd.createChar(1, doC);
  pinMode(Buzzer, OUTPUT);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Nhiet do");
  lcd.setCursor(10,0);
  lcd.write(byte(0));
  lcd.setCursor(10,1);
  lcd.write(byte(0));
  lcd.setCursor(10,2);
  lcd.write(byte(0));
  lcd.setCursor(10,3);
  lcd.write(byte(0));
  lcd.setCursor(0,2);
  lcd.print("-----------");
  lcd.setCursor(11,2);
  lcd.print("---------");

  lcd.setCursor(13,0);
  lcd.print("Do am");
  lcd.setCursor(4,1);
  lcd.print(round(t));
  lcd.write(byte(1));
  lcd.setCursor(14,1);
  lcd.print(round(h));
  lcd.print("%");
  if(t<20){
    lcd.setCursor(4,3);
    lcd.print("Thap");
    } else
      if(t>28){
        lcd.setCursor(4,3);
        lcd.print("Cao");
      }
      else
      {
        lcd.setCursor(2,3);
        lcd.print("An toan");
      }
      if(h<40){
        lcd.setCursor(13,3);
        lcd.print("Thap");
      }else if (h>60){
        lcd.setCursor(14,3);
        lcd.print("Cao");
      } else {
        lcd.setCursor(12,3);
        lcd.print("An toan");
      }
  if ((t>=20 && t<=28) && (h>=40 && h<=60))
    noTone(Buzzer);
  else
    tone(Buzzer,300,500);
  delay(1000);
}
