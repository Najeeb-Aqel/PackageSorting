int enA = 10;
int in1 = 9;
int in2 = 8;
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int count = 0;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup()
{
  // set all the motor control pins to outputs
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
 // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 100);

if(count == 0)
{  
  myservo.write(180);                
  delay(2000);                           // waits for the servo to get there
  count++;
}
  
  
}
