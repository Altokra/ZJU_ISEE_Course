void setup() {
  // 初始化串口通信，波特率115200
  Serial.begin(115200);
  
  // 设置ADC分辨率为12位 (范围 0-4095)
  analogReadResolution(12);
}

void loop() {
  // 读取引脚 32 的模拟值
  int analogValue = analogRead(32);
  // 读取引脚 32 的等效毫伏值
  int analogVolts = analogReadMilliVolts(32);

  // 打印读取到的数值
  Serial.printf("ADC analog value = %d\n", analogValue);
  Serial.printf("ADC millivolts value = %d\n", analogVolts);

  // 延时1秒，避免刷新过快影响阅读
  delay(1000); 
}
