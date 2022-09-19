#include <Arduino.h>
#include <DabbleESP32.h>
#include <SparkFun_TB6612.h>

using namespace std;

#define AIN1 25
#define BIN1 27
#define AIN2 33
#define BIN2 14
#define PWMA 32
#define PWMB 13
#define STBY 26

const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup() {
  Serial.begin(115200);
  Dabble.begin("Billu-Bot");
}

void loop(){
  Dabble.processInput();
  float x_axis = GamePad.getXaxisData();
  int radius = GamePad.getRadius();
  
  int pwm1 = 0;
  int pwm2 = 0;
  int mapped_x = x_axis * 55 / 7; // decreasing factor 55
  int mapped_radius = radius * 255 / 7;

  pwm1 += (mapped_radius + mapped_x);
  pwm2 += (mapped_radius - mapped_x);

  if (pwm1 > 255) pwm1 = 255;
  if (pwm2 > 255) pwm2 = 255;

  motor1.drive(pwm1);
  motor2.drive(pwm2);
}