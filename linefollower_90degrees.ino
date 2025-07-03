#define rightF 10
#define rightB 11
#define leftF 6
#define leftB 5

#define EN0 12
#define EN1 2

#define sensorLeft 8
#define sensorRight 7

bool sensorRightRead = false;
bool sensorLeftRead = false;

const int speed = 187;
const int maxSpeed = 212;
const int lowSpeed = 125;
const int stopped = 0;


void setup() {
  pinMode(rightF, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(leftF, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(EN0, OUTPUT);
  pinMode(EN1, OUTPUT);

  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);

  digitalWrite(EN0, HIGH);
  digitalWrite(EN1, HIGH);
}

void loop() {
  sensorLeftRead = digitalRead(sensorLeft);
  sensorRightRead = digitalRead(sensorRight);
  if((sensorLeftRead == HIGH) && (sensorRightRead == HIGH)){
    analogWrite(leftB, stopped);
    analogWrite(rightB, stopped);
    analogWrite(leftF, maxSpeed);
    analogWrite(rightF, maxSpeed);
  }
  if((sensorLeftRead == LOW) && (sensorRightRead == HIGH)){
    analogWrite(leftF, stopped);
    analogWrite(leftB, speed);
    analogWrite(rightF, lowSpeed);
  }
  if((sensorLeftRead == HIGH) && (sensorRightRead == LOW)){
    analogWrite(rightF, stopped);
    analogWrite(leftF, lowSpeed);
    analogWrite(rightB, speed);
  }
 if((sensorLeftRead == LOW) && (sensorRightRead == LOW)){
    analogWrite(leftF, lowSpeed);
    analogWrite(rightF, lowSpeed);
    analogWrite(leftB, stopped);
    analogWrite(rightB, stopped);
  }
}
