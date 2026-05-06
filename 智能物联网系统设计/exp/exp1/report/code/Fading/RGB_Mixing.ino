#define RED_PIN 18
#define GREEN_PIN 17
#define BLUE_PIN 16

void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

// 封装颜色设置函数
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(RED_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLUE_PIN, blueValue);
}

void loop() {
  // 1. 从红色渐变到黄色 (红+绿)
  for (int i = 0; i <= 255; i++) {
    setColor(255, i, 0); 
    delay(10);
  }
  // 2. 从黄色渐变到绿色 (减去红色)
  for (int i = 255; i >= 0; i--) {
    setColor(i, 255, 0); 
    delay(10);
  }
  // 3. 从绿色渐变到青色 (绿+蓝)
  for (int i = 0; i <= 255; i++) {
    setColor(0, 255, i); 
    delay(10);
  }
  // 4. 从青色渐变到蓝色 (减去绿色)
  for (int i = 255; i >= 0; i--) {
    setColor(0, i, 255); 
    delay(10);
  }
  // 5. 从蓝色渐变到紫色 (蓝+红)
  for (int i = 0; i <= 255; i++) {
    setColor(i, 0, 255); 
    delay(10);
  }
  // 6. 从紫色渐变回红色 (减去蓝色)
  for (int i = 255; i >= 0; i--) {
    setColor(255, 0, i); 
    delay(10);
  }
}