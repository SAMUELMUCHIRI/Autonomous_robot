#include <Servo.h>
Servo myservo;
float distance;
int right;
int left;
int center;
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
int backled1 = 51;
int backled2 = 53;
int rightled = 48;
int leftled = 49;
int rightir = 10;
int leftir = 9;

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
  pinMode(backled1, OUTPUT);
  pinMode(backled2, OUTPUT);
  pinMode(rightled, OUTPUT);
  pinMode(leftled, OUTPUT);
  pinMode(leftir, INPUT);
  pinMode(rightir, INPUT);
  
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
    // Send a 10 microsecond pulse to trigger the sensor
    int distance = object_distance();
    int leftstate=digitalRead(leftir);
    int rightstate=digitalRead(rightir);
     if ( distance >= 50)
    {  
    if((leftstate == 1) && (rightstate == 1))
    {
    digitalWrite(rightled, HIGH);
    digitalWrite(leftled, HIGH);
    for(int a =100; a< 156;a++)
    {
      motorForward(a,a);
      delay(1);
    }  
    digitalWrite(rightled, LOW);
    digitalWrite(leftled, LOW);
    }
    else if((leftstate == 0) && (rightstate == 1))
    {
      motorReverse(140);
      delay(50);
      motorspinright(130);
      delay(40);


    }
      else if((leftstate == 1) && (rightstate == 0))
    {
      motorReverse(140);
      delay(50);
      motorspinleft(130);
      delay(40);
           
    }
   
   
   
   

    }
    else if(distance<50)
    { 
     scanarea();
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

void motorspinleft(int rturn) {
  digitalWrite(motorPin1A, LOW);
  digitalWrite(motorPin2A, HIGH);
  analogWrite(enablePinAA, 80);
  digitalWrite(motorPin1B, LOW);
  digitalWrite(motorPin2B, HIGH);
  analogWrite(enablePinBB, 80);
  digitalWrite(motorPin3A, LOW);
  digitalWrite(motorPin4A, HIGH);
  analogWrite(enablePinCC, rturn);
  digitalWrite(motorPin3B, LOW);
  digitalWrite(motorPin4B, HIGH);
  analogWrite(enablePinDD, rturn);
  //Serial.println("Motor Stopped");
}

void motorspinright(int turn) {
   digitalWrite(motorPin1A, HIGH);
  digitalWrite(motorPin2A, LOW);
  analogWrite(enablePinAA, turn);
  digitalWrite(motorPin1B, HIGH);
  digitalWrite(motorPin2B, LOW);
  analogWrite(enablePinBB, turn);
  digitalWrite(motorPin3A, HIGH);
  digitalWrite(motorPin4A, LOW);
  analogWrite(enablePinCC, 80);
  digitalWrite(motorPin3B, HIGH);
  digitalWrite(motorPin4B, LOW);
  analogWrite(enablePinDD, 80);; 
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

void smallscan()
{
  int center = object_distance();
   for (int i = 90; i < 130; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }
   int right=object_distance();
  delay(5);
  
  for (int i = 129; i >49 ; i--) 
  {
  myservo.write(i); 
  delay(1);                 
  }
  delay(5);
  int left = object_distance();
   for (int i = 50; i < 91 ; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }
}

void navigate()
{
   if (((center > left ) || (center == left )) && ((center > right ) || (center == right )))
{
  int leftstate=digitalRead(leftir);
  int rightstate=digitalRead(rightir);
  digitalWrite(rightled, HIGH);
  digitalWrite(leftled, HIGH);
    if((leftstate == 1) && (rightstate == 1))
  {
  digitalWrite(rightled, HIGH);
  digitalWrite(leftled, HIGH);
    for(int a =100;a< 130;a++)
  {
    motorForward(a,a);
    delay(4);
  }  
  digitalWrite(rightled, LOW);
  digitalWrite(leftled, LOW);
  }
  else if((leftstate == 0) && (rightstate == 1))
    {
      motorReverse(140);
      delay(50);
      motorspinright(130);
      delay(40);


    }
      else if((leftstate == 1) && (rightstate == 0))
    {
      motorReverse(140);
      delay(50);
      motorspinleft(130);
      delay(40);
           
    }
}
else if ( (right > center ) &&  (right > left ))
{
  digitalWrite(rightled, HIGH);
  motorspinright(130);
  delay(50);
  digitalWrite(rightled, LOW);


}
  else if (( left > center  ) && (left > right ))
{
  digitalWrite(leftled, HIGH);
  motorspinleft(130);
  delay(50);
  digitalWrite(leftled, LOW);  
  }
}


void scanarea()
{
    
  int center = object_distance();
   for (int i = 90; i < 170; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }
  int right=object_distance();
  delay(5);
  
  for (int i = 169; i >9 ; i--) 
  {
  myservo.write(i); 
  delay(1);                 
  }
  delay(5);
  int left = object_distance();
   for (int i = 10; i < 91 ; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }


if ( center<=25) 
{
 escape_block();
}
else 
{
  navigate();

}
 
}

void escape_block()
{
  
  digitalWrite(backled1, HIGH);
  digitalWrite(backled2, HIGH);
  
    for(int a =130; a<170 ;a++)
  {
    motorReverse(a);
    delay(4);
  }  
 

   for (int i = 90; i < 170; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }
  int right=object_distance();
  delay(10);
  
  for (int i = 169; i >9 ; i--) 
  {
  myservo.write(i); 
  delay(1);                 
  }
  delay(10);
  int left = object_distance();
   for (int i = 10; i < 91 ; i++) 
  {
  myservo.write(i); 
  delay(1);                 
  }

 


  if (left > right )
  {
    
    digitalWrite(leftled, HIGH);
    motorspinleft(150);
    delay(30);
    digitalWrite(leftled, LOW);
   
  }
  else if (right > left)
  {
    
    digitalWrite(rightled, HIGH);
    motorspinright(150);
    delay(30);
    digitalWrite(rightled, LOW);
   
  }
 

digitalWrite(backled1, LOW);
digitalWrite(backled2, LOW);
}
