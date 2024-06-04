#include <Servo.h> //library
#define trigPin 9
#define echoPin 8
#define buzzer 11
Servo servo;  //sublibrary create object class class
//const int buzzer=11;
//int sound = 250;
void setup() {
Serial.begin (9600);  /// Initialize serial communication at 9600 bits per sec
pinMode(trigPin, OUTPUT); // Set trigPin as an output
pinMode(echoPin, INPUT); // Set echoPin as an input
servo.attach(7);// Attach the servo to pin 7
pinMode(buzzer, OUTPUT);// Set buzzer as an output
}
void loop() {
long duration, distance;  //variables declaration
digitalWrite(trigPin, LOW); 
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 10) {
Serial.println("Water is Empty");
//servo.write(90);
//delay(1500);
digitalWrite(buzzer,HIGH);
}
else {
//servo.write(0);
digitalWrite(buzzer,LOW);
}
if (distance > 60 || distance <= 10){
Serial.println("Feeding...");
servo.write(180);
delay(1500); //feeding time can be changed
}
else {
Serial.print(distance);
Serial.println(" cm");
servo.write(0);
}
delay(500);
}



