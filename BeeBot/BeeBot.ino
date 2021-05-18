//Clone Time

int leftMotor = 6;
int rightMotor = 5;
int fwdButton = 3;
int leftButton = 4;
int rightButton = 2;
int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup()
{
  pinMode(fwdButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(fwdButton) == HIGH)
  {
    moveFwd();
  }
  if (digitalRead(leftButton) == HIGH)
  {
    turnLeft();
  }
  if (digitalRead(rightButton) == HIGH)
  {
    turnRight();
  }
}

void moveFwd()
{
  if (distanceCheck() == false)
  {
    analogWrite(leftMotor, 255);
    analogWrite(rightMotor, 255);
    delay(500);
    analogWrite(leftMotor, 0);
    analogWrite(rightMotor, 0);
  }
}

void turnLeft()
{
  if (distanceCheck() == false)
  {
    analogWrite(leftMotor, 255);
    delay(500);
    analogWrite(leftMotor, 0);
  }
}

void turnRight()
{
  if (distanceCheck() == false)
  {
    analogWrite(rightMotor, 255);
    delay(500);
    analogWrite(rightMotor, 0);
  }
}

void reverse()
{
  //No, not gonna happen
}

bool distanceCheck()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  //Serial.println(distance);
  if (distance < 20)
  {
    return true;
  }
  else
  {
    return false;
  }
}