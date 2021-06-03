//LiquidCrystal_I2C.h 作者：johnrickman 版本：1.1 下載位址：https://github.com/johnrickman/LiquidCrystal_I2C 
#include <LiquidCrystal_I2C.h>
//EduIntro.h 作者：Arduino LLC 版本：0.0.13 下載位址：https://github.com/arduino/EduIntro
#include <EduIntro.h>
LiquidCrystal_I2C lcd(0x27,16,2);//定義IIC位置為0x27 LCD為16x2
DHT11 dht11(2);//定義DHT11資料腳為2
int C;//全域變數C為攝氏溫度
int H;//全域變數H為相對溼度

void setup() 
{
  lcd.init();//LCD初始化
  lcd.backlight();//開啟背光
}

void loop() 
{
  dht11.update();//更新資料
  C = dht11.readCelsius();
  H = dht11.readHumidity();
  
  lcd.setCursor(0,0);//調整游標至第0字元第0行
  lcd.print("Temp:");//顯示Temp
  lcd.setCursor(5,0);
  lcd.print(C);//輸出溫度
  lcd.setCursor(7,0);
  lcd.print(char(223));//特殊字元°
  lcd.setCursor(8,0);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.setCursor(4,1);
  lcd.print(H);
  lcd.setCursor(6,1);
  lcd.print("%");
  delay(1000);
}
