//Clone Time

int leftMotor = 6;
int rightMotor = 5;
int fwdButton = 3;
int leftButton = 4;
int rightButton = 2;
//Vars for Ultrasonic Sensor
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
  //As there is no array function, this code only serves to check the buttons, and to perform an action on a press.
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
    //Powers the motor, One motor is faster for some reason
    analogWrite(leftMotor, 210);
    analogWrite(rightMotor, 255);
    delay(250);
    analogWrite(leftMotor, 0);
    analogWrite(rightMotor, 0);
  }
  //Serial.println("fwd");
}

void turnLeft()
{
  if (distanceCheck() == false)
  {
    analogWrite(leftMotor, 210);
    delay(500);
    analogWrite(leftMotor, 0);
  }
  //Serial.println("left");
}

void turnRight()
{
  if (distanceCheck() == false)
  {
    analogWrite(rightMotor, 255);
    delay(500);
    analogWrite(rightMotor, 0);
  }
  //Serial.println("right");
}

void reverse()
{
  //No, not gonna happen
}

bool distanceCheck()
{
  //Code to check if the Bot is within 20 cm of a wall, allowing for slop in the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  //Serial.println(distance);
  //Returns a true or false depending on wether the bot thinks it'll crash
  if (distance < 20)
  {
    return true;
  }
  else
  {
    return false;
  }
}