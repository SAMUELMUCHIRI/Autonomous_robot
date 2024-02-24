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
void setup() {

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
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {

  motorForward();
  delay(2000); 
  motorright();
  delay(2000);
 
  motorStop();
  delay(1000); 
  motorleft();
  delay(2000);

  motorReverse();
  delay(2000); 

  motorStop();
  delay(1000); 
}

void motorForward() {
  digitalWrite(motorPin1A, HIGH);
  digitalWrite(motorPin2A, LOW);
  analogWrite(enablePinAA, 255);
  digitalWrite(motorPin1B, HIGH);
  digitalWrite(motorPin2B, LOW);
  analogWrite(enablePinBB, 255);
  digitalWrite(motorPin3A, LOW);
  digitalWrite(motorPin4A, HIGH);
  analogWrite(enablePinCC, 255);
  digitalWrite(motorPin3B, LOW);
  digitalWrite(motorPin4B, HIGH);
  analogWrite(enablePinDD, 255); 
  Serial.println("Motor Forward");
}

void motorReverse() {
   digitalWrite(motorPin1A, LOW);
  digitalWrite(motorPin2A, HIGH);
  analogWrite(enablePinAA, 255);
  digitalWrite(motorPin1B, LOW);
  digitalWrite(motorPin2B, HIGH);
  analogWrite(enablePinBB, 255);
  digitalWrite(motorPin3A, HIGH);
  digitalWrite(motorPin4A, LOW);
  analogWrite(enablePinCC, 255);
  digitalWrite(motorPin3B, HIGH);
  digitalWrite(motorPin4B, LOW);
  analogWrite(enablePinDD, 255); 
  Serial.println("Motor Reverse");
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
  Serial.println("Motor Stopped");
}

void motorright() {
  digitalWrite(motorPin1A, LOW);
  digitalWrite(motorPin2A, HIGH);
  analogWrite(enablePinAA, 255);
  digitalWrite(motorPin1B, LOW);
  digitalWrite(motorPin2B, HIGH);
  analogWrite(enablePinBB, 255);
  digitalWrite(motorPin3A, LOW);
  digitalWrite(motorPin4A, HIGH);
  analogWrite(enablePinCC, 255);
  digitalWrite(motorPin3B, LOW);
  digitalWrite(motorPin4B, HIGH);
  analogWrite(enablePinDD, 255);
  Serial.println("Motor Stopped");
}

void motorleft() {
   digitalWrite(motorPin1A, HIGH);
  digitalWrite(motorPin2A, LOW);
  analogWrite(enablePinAA, 255);
  digitalWrite(motorPin1B, HIGH);
  digitalWrite(motorPin2B, LOW);
  analogWrite(enablePinBB, 255);
  digitalWrite(motorPin3A, HIGH);
  digitalWrite(motorPin4A, LOW);
  analogWrite(enablePinCC, 255);
  digitalWrite(motorPin3B, HIGH);
  digitalWrite(motorPin4B, LOW);
  analogWrite(enablePinDD, 255);; 
  Serial.println("Motor Stopped");
}
