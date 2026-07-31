#include <Servo.h>

Servo myServo;

const int pingPin = 9;   // حساس المسافة
const int servoPin = 6;  // السيرفو
const int ledPin = 7;    // LED

long duration;
float distance;

void setup() {
  myServo.attach(servoPin);
  myServo.write(0);

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);

  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    myServo.write(90);
    digitalWrite(ledPin, HIGH);
  } else {
    myServo.write(0);
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}