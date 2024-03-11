#include <Servo.h>
Servo myservo;
float distance;
int right;
int left;
//rightwheels
//A
const int motorPin1A = 24; 
const int motorPin2A = 25;  
const int enablePinAA = 5;  
//B
const int motorPin1B = 26; 
const int motorPin2B = 27;  
const int enablePinBB = 4; 
//leftwheels
//A
const int motorPin3A = 28; 
const int motorPin4A = 29;  
const int enablePinCC = 3; 
//B
const int motorPin3B = 30; 
const int motorPin4B = 31;  
const int enablePinDD = 2;  
const int trigPin = 7;
const int echoPin = 6;
void setup() {
  myservo.attach(8);

  pinMode(motorPin1A, OUTPUT);
  pinMode(motorPin2A, OUTPUT);
  pinMode(enablePinAA, OUTPUT);
  pinMode(motorPin1B, OUTPUT);
  pinMode(motorPin2B, OUTPUT);
  pinMode(enablePinBB, OUTPUT);
  pinMode(motorPin3A, OUTPUT);
  pinMode(motorPin4A, OUTPUT);
  pinMode(enablePinCC, OUTPUT);
  pinMode(motorPin3B, OUTPUT);
  pinMode(motorPin4B, OUTPUT);
  pinMode(enablePinDD, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
    // Send a 10 microsecond pulse to trigger the sensor
  object_distance();
  //scanarea();

  
  if (distance > 15)
  {
  motorForward(155 , 155);
  delay(100);
  } 
  else if (distance < 15)
  {
  //motorStop();
  scanarea();
  delay(100);

  //delay(200);

  

  }

  }
 



void motorForward(int right_speed , int left_speed) 
{
  digitalWrite(motorPin1A, HIGH);
  digitalWrite(motorPin2A, LOW);
  analogWrite(enablePinAA, right_speed);
  digitalWrite(motorPin1B, HIGH);
  digitalWrite(motorPin2B, LOW);
  analogWrite(enablePinBB, right_speed);
  digitalWrite(motorPin3A, LOW);
  digitalWrite(motorPin4A, HIGH);
  analogWrite(enablePinCC, left_speed);
  digitalWrite(motorPin3B, LOW);
  digitalWrite(motorPin4B, HIGH);
  analogWrite(enablePinDD, left_speed); 
  Serial.println("Motor Forward");
}

void motorReverse(int speed) {
   digitalWrite(motorPin1A, LOW);
  digitalWrite(motorPin2A, HIGH);
  analogWrite(enablePinAA, speed);
  digitalWrite(motorPin1B, LOW);
  digitalWrite(motorPin2B, HIGH);
  analogWrite(enablePinBB, speed);
  digitalWrite(motorPin3A, HIGH);
  digitalWrite(motorPin4A, LOW);
  analogWrite(enablePinCC, speed);
  digitalWrite(motorPin3B, HIGH);
  digitalWrite(motorPin4B, LOW);
  analogWrite(enablePinDD, speed); 
  //Serial.println("Motor Reverse");
}

void motorStop() {
  digitalWrite(motorPin1A, LOW);
  digitalWrite(motorPin2A, LOW);
  analogWrite(enablePinAA, 0);
  digitalWrite(motorPin1B, LOW);
  digitalWrite(motorPin2B, LOW);
  analogWrite(enablePinBB, 0);
  digitalWrite(motorPin3A, LOW);
  digitalWrite(motorPin4A, LOW);
  analogWrite(enablePinCC, 0);
  digitalWrite(motorPin3B, LOW);
  digitalWrite(motorPin4B, LOW);
  analogWrite(enablePinDD, 0); 
 // Serial.println("Motor Stopped");
}

void motorspinright(int rturn) {
  digitalWrite(motorPin1A, LOW);
  digitalWrite(motorPin2A, HIGH);
  analogWrite(enablePinAA, rturn);
  digitalWrite(motorPin1B, LOW);
  digitalWrite(motorPin2B, HIGH);
  analogWrite(enablePinBB, rturn);
  digitalWrite(motorPin3A, LOW);
  digitalWrite(motorPin4A, HIGH);
  analogWrite(enablePinCC, rturn);
  digitalWrite(motorPin3B, LOW);
  digitalWrite(motorPin4B, HIGH);
  analogWrite(enablePinDD, rturn);
  //Serial.println("Motor Stopped");
}

void motorspinleft(int turn) {
   digitalWrite(motorPin1A, HIGH);
  digitalWrite(motorPin2A, LOW);
  analogWrite(enablePinAA, turn);
  digitalWrite(motorPin1B, HIGH);
  digitalWrite(motorPin2B, LOW);
  analogWrite(enablePinBB, turn);
  digitalWrite(motorPin3A, HIGH);
  digitalWrite(motorPin4A, LOW);
  analogWrite(enablePinCC, turn);
  digitalWrite(motorPin3B, HIGH);
  digitalWrite(motorPin4B, LOW);
  analogWrite(enablePinDD, turn);; 
  //Serial.println("Motor Stopped");
}

int object_distance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse from the echo pin
  long duration = pulseIn(echoPin, HIGH);
  
  // Convert the duration to distance
  distance = duration * 0.034 / 2; 
  return distance;
  
}

void scanarea()
{
   for (int i = 95; i < 170; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }
   int right=object_distance();
  delay(10);
  
  for (int i = 169; i >21 ; i--) 
  {
  myservo.write(i); 
  delay(1);                 
  }
  delay(10);
  int left = object_distance();
   for (int i = 20; i < 96 ; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }

Serial.print("left :");
Serial.print(left);

Serial.print("right :");
Serial.print(right);


  if (left > right )
  {
    //motorReverse(200);
    //delay(50);
   motorspinright(170);
    delay(150);
    motorspinleft(170);
    delay(40);
  }
  else if (right > left)
  {
    //motorReverse(50);
    //delay(50);
    motorspinleft(170);
    delay(150);
    motorspinright(170);
    delay(40);
  }
  else if (right =left )
  {
    motorReverse(250);

    delay(150);
    scanarea();
  }

}
