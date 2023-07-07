# Arduino# ArduinoUNO-Temperature-measurement-and-alarm-Wokwi
## Project description
This project collects temperature and humidity, outputs to LCD, if temperature or humidity is at unsafe level (Temperature > 28 || Temperature < 20 || Humidity > 60 || Humidity < 60), an alarm will be displayed on the LCD with a buzzer sound. This project is built on wokwi.com
## Components
- Arduino UNO
- LCD 20x4 I2C
- DHT22
- Buzzer

## Connections diagram
![image](https://github.com/PDrole/Arduino/assets/135306841/cae3e552-a5c8-492d-bb1d-68eea318222f)

The image above corresponds to the code below:
#### CODE in diagram.json:
```
 "connections": [
    [ "lcd1:GND", "uno:GND.2", "black", [ "h-50.67", "v213.74", "h-147.33" ] ],
    [ "lcd1:VCC", "uno:5V", "red", [ "h-34.56", "v219.45", "h-172.94" ] ],
    [ "lcd1:SDA", "uno:A4", "green", [ "h-23.83", "v177.74", "h-97.67" ] ],
    [ "lcd1:SCL", "uno:A5", "green", [ "h-11.3", "v174.51", "h-100.7" ] ],
    [ "dht1:VCC", "uno:5V", "red", [ "h-128.38", "v281.71", "h193.01" ] ],
    [ "dht1:GND", "uno:GND.1", "black", [ "h0.29", "v32.08", "h20.56" ] ],
    [ "dht1:SDA", "uno:5", "green", [ "v51.76", "h132.65" ] ],
    [ "bz1:1", "uno:GND.1", "green", [ "v55.12", "h-112.17" ] ],
    [ "bz1:2", "uno:2", "green", [ "v0" ] ]
  ],
```
Connected array consisting of 4 elements:
- The first element is the pin and name of the source device
- The second element is the pin and name of the target device
- The third element is the color of the wire connecting the pin of the source device and the pin of the target device
- The fourth element is the location of the connection wire between the pin of the source device and the pin of the target device:
    * "v" followed by a number of pixels: move vertically (up/down)
    * "h" followed by a number of pixels: move horizontally (left/right)

## Running Projects
![image](https://github.com/PDrole/Arduino/assets/135306841/d19ddd48-cca8-4d94-bb7e-16077a5f7c5c)
## Special characters in LCD
The LCD20x4 uses the Hitachi HD44780 LCD Controller chip. The chip comes with a built-in font, as well as the ability to define up to 8 (0-7) custom characters.

Due to 2 special characters "0C" and "|" are not defined in LCD, so I will define them using createChar method of LiquidCrystal_I2C library and print them to LCD using write() method.
```
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
  lcd.write(byte(0));
  lcd.write(byte(1));
}
```
byte dauGach[] means "|" because each square on LCD screen corresponds to 1 byte, in each square there will be 40 pixels of 5 columns and 8 rows, each row corresponds to 1 Bit (1 on, 0 off). Therefore, I will define B00100 in each row to form the "|" character, see illustration below.
![image](https://github.com/PDrole/Arduino/assets/135306841/86137e6a-df87-4cd0-abc1-9597b8c0d46f)

If you find it difficult to define, you can visit the website https://maxpromer.github.io/LCD-Character-Creator/ to customize the desired character.
## Link Projects
https://wokwi.com/projects/369596305046237185
