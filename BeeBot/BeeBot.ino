//Clone Time
int motorPin1 = 5;
int motorPin2 = 3;
int buttonPin = 2;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  Serial.println(digitalRead(buttonPin));
  int fwd = digitalRead(buttonPin);
  if (fwd==HIGH) {
    analogWrite(motorPin1, 200);
    analogWrite(motorPin2, 200);
  }
  else {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
  }
}
