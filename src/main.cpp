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
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    forward(motor1, motor2, 255);
  } else if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    back(motor1, motor2, 255);
  } else if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    left(motor1, motor2, 255);
  } else if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    right(motor1, motor2, 255);
  } else
  {
    brake(motor1, motor2);
  }
  Serial.print('\t');
}