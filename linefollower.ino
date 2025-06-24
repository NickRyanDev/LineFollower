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

const int speed = 150;
const int maxSpeed = 250;
const int lowSpeed = 20;
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
    analogWrite(leftF, maxSpeed);
    analogWrite(rightF, maxSpeed);
  }
  if((sensorLeftRead == LOW) && (sensorRightRead == HIGH)){
    analogWrite(leftF, lowSpeed);
    analogWrite(rightF, speed);
  }
  if((sensorLeftRead == HIGH) && (sensorRightRead == LOW)){
    analogWrite(leftF, speed);
    analogWrite(rightF, lowSpeed);
  }
  else{
    analogWrite(leftF, stopped;
    analogWrite(rightF, stopped);
  }
}
