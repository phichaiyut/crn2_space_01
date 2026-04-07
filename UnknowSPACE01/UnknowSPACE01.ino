#include <UnknowSPACE_01.h>

void setup() {
  RobotSetup();
  pinMode(signal_pin, INPUT);


  RobotSetupSpeedKpKd();
  SensorValue(45, 44, 43, 44, 45, 42, 42, 42, 43, 42, 45, 45, 46, 43, 43, 44, 858, 846, 799, 839, 828, 827, 816, 786, 826, 801, 839, 811, 838, 812, 806, 834);
  TurnSpeedLeft(4, 25, 100, 30);    // ค่าเลี้ยวซ้าย TurnSpeedLeft(ช่องเซนเซอร์, มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  TurnSpeedRight(11, 100, 25, 30);  // ค่าเลี้ยวขวา TurnSpeedRight(ช่องเซนเซอร์, มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  TrackLineColor(0);                 // สีของเส้น 1 = ขาว , 0 = ดำ

  ModeSpdPID(0, 100, -25);
  Dottedline(0);      //ไม่มีเส้นประใส่ 0  >> มีเส้นประใส่ 1
  LoadCalibration();  //โหลดค่าจาก EEPROM

  //SerialSensor();           // Serial Monitor ค่าของ Sensor
  //SerialCalibrateSensor();  // Serial Monitor ค่าของ Sensor ที่ Calibrate แล้ว
  //CaliberateRobotSensor();  // Serial Monitor Calibrate ค่าแสงหุ่นยนต์
  //SerialPosition();
  // OK();  // รอจนกว่าจะกดปุ่ม OK
  Mode();
  delay(100);  // หน่วงเวลา 0.1 วินาที
  Beep(200);   // ใช้ buzzer เป็นเวลา 0.2 วินาที
  // TestMotor();
  //FinishWaitOK();
  // คำสั่งเจอแยก >> 'l'=เลี้ยวซ้าย ,'r'=เลี้ยวขวา ,'p'=ตรง ,'s'=หยุด
  // PID จนกว่าจะเจอแยก TrackCross(Speed, Kp , Kd , 'คำสั่งเจอแยก')
  // KP -> ค่าเข้าโค้ง ยิ่งเพิ่มยิ่งเข้าโค้งไว (0.01 - 0.025)
  // KD -> ค่าทำให้หุ่นนิ่ง ยิ่งเพิ่มยิ่งนิ่ง (0.08 - 0.5)
  // TrackCrossL(40, 10, 80, 'r');  // ใช้เซนเซอร์คู่ซ้ายในการนับแยก
  // TrackCrossR(100, 20, 20 ,'r');  // ใช้เซนเซอร์คู่ขวาในการนับแยก
  // TrackCrossC(40, 10, 80, 'r');  // ใช้เซนเซอร์คู่กลางในการนับแยก
  // TrackTime(100, 30, 30, 1500);
  // PID ด้วยเวลา TrackTime(Speed, Kp , Kd, เวลา); >> เวลา 1000 = 1 วินาที

  // Move(30,-30,2000);
  //คำสั่งเคลื่อนที่ Move(SpeedLeft,SpeedRight,TimeDelay);

  //__________________________________วางโค้ดใหม่หลังจากนี้บรรทัดนี้ทั้งหมด______________________________________________________________________

  Mission();



  //____________________________________ห้ามวางโค้ดหลังจากบรรทัดนี้____________________________________________________________________________

}  //_________________ปีกกาตัวนี้ห้ามลบ______________________________
void loop() {
  // put your main code here, to run repeatedly:
  MotorStop();
}
