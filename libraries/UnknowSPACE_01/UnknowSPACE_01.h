#include "Sensor.h"
#include "Motor.h"
#include "Initial.h"
#include "ForwardBackwardAndTurn.h"
#include "PID.h"
void RobotSetup() {
  Serial.begin(115200);
  pinMode(PH1, OUTPUT);
  pinMode(EN1, OUTPUT);  
  pinMode(PH2, OUTPUT);
  pinMode(EN2, OUTPUT);
  Beep(100);
  delay(50);
  Beep(100);
}


void Mode() {
  unsigned long pressStart = 0;

  // รอจนกว่าจะกดปุ่ม OK
  while (OK_PUSH() != PRESS)
    ;

  pressStart = millis();  // เวลาเริ่มกด

  // รอจนกว่าจะปล่อยปุ่ม
  while (OK_PUSH() == PRESS)
    ;

  unsigned long pressDuration = millis() - pressStart;

  if (pressDuration >= 2000) {
    b_beebb();
    delay(300);
    OK();
    // กดค้างเกิน 2 วินาที
    Serial.println(">>> Calibrate Sensor Start");
    CalibrateSensor(20, 200);
SaveCalibration();
    b_beebb();
    Serial.println(">>> Calibrate Sensor Done");
    OK();
  } else {
    // กดสั้นกว่า 2 วิ
    Serial.println("Exit Mode (Short Press)");
    return;
  }
}