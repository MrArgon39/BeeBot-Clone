//Clone Time

int leftMotor = 6;
int rightMotor = 5;
int fwdButton = 3;
int leftButton = 4;
int rightButton = 2;

void setup()
{
  pinMode(fwdButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
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
  analogWrite(leftMotor, 200);
  analogWrite(rightMotor, 200);
  delay(100);
  analogWrite(leftMotor, 0);
  analogWrite(rightMotor, 0);
}

void turnLeft()
{
  analogWrite(leftMotor, 200);
  delay(100);
  analogWrite(leftMotor, 0);
}

void turnRight()
{
  analogWrite(rightMotor, 200);
  delay(100);
  analogWrite(rightMotor, 0);
}

void reverse()
{
  //No, not gonna happen
}
