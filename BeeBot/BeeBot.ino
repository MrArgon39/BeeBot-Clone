//Clone Time
int leftMotor = 5;
int rightMotor = 3;
int buttonPin = 2;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  Serial.println(digitalRead(buttonPin));
  if (digitalRead(buttonPin) == HIGH) {
    moveFwd();
  }
}

void moveFwd() {
  analogWrite(leftMotor, 200);
  analogWrite(rightMotor, 200);
  delay(100);
  analogWrite(leftMotor, 0);
  analogWrite(rightMotor, 0);

}

void turnLeft() {
  analogWrite(leftMotor, 200);
  delay(100);
  analogWrite(leftMotor, 0);
}

void turnRight() {
  analogWrite(rightMotor, 200);
  delay(100);
  analogWrite(rightMotor, 0);
}

void reverse() {
  //No
}
