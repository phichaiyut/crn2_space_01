
#define PH1 3
#define EN1 5 

#define PH2 2 
#define EN2 6 

void Motor1(int Pow) {
  Pow = constrain(Pow, -100, 100);

  if (Pow == 0) {
    analogWrite(EN1, 0);
    return;
  }

  bool dir = (Pow > 0);
  int pwm = map(abs(Pow), 0, 100, 0, 255);

  digitalWrite(PH1, dir);
  analogWrite(EN1, pwm);
}

void Motor2(int Pow) {
  Pow = constrain(Pow, -100, 100);

  if (Pow == 0) {
    analogWrite(EN2, 0);
    return;
  }

  bool dir = (Pow > 0);
  int pwm = map(abs(Pow), 0, 100, 0, 255);

  digitalWrite(PH2, dir);
  analogWrite(EN2, pwm);
}

void Motor(int leftsp, int rightsp) {
  Motor1(leftsp);
  Motor2(rightsp);
}

void Move(int l, int r, int deelay) {
  Motor(l, r);
  delay(deelay);
}

void MotorStop() {
  Motor(0,0);
  delay(5);
}

void MotorStop(int tim) {
  Motor(0,0);
  delay(tim);
}