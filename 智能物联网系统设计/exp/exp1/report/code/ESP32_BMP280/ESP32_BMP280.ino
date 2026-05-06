#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

#define BMP_SDA 21 // I2C SDA 引脚
#define BMP_SCL 22 // I2C SCL 引脚
Adafruit_BMP280 bmp280;

void setup() {
  Serial.begin(115200); 
  Serial.println("Initializing BMP280..."); 
  
  // 初始化I2C通信，BMP280常见地址为0x76或0x77
  boolean status = bmp280.begin(0x76); 
  if (!status) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  float temp = bmp280.readTemperature(); // 读取温度值，单位摄氏度
  float press = bmp280.readPressure() / 100.0F; // 读取大气压并转换为hPa
  float altitude = bmp280.readAltitude(1013.25); // 读取估计海拔(以标准大气压为基准)

  Serial.print("Temperature: "); 
  Serial.print(temp); 
  Serial.println(" *C"); 

  Serial.print("Pressure: ");
  Serial.print(press); 
  Serial.println(" hPa"); 

  Serial.print("Altitude: ");
  Serial.print(altitude); 
  Serial.println(" m");
  
  Serial.println("-------------------");
  delay(2000); // 每两秒刷新一次
}