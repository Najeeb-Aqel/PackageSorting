
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>
#include <Servo.h>

Servo myservo;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 37, 39, 43, 45);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(120);
  // initialize the serial port:
  Serial.begin(9600);
  myservo.attach(49);
  myservo.write(90);  
  pinMode(47,INPUT);
}
int count =0;
int angle = 2090;

//four floor = 2780
//third floor = 2090
//second floor = 1050
//first floor = 0
void goToFloor(int NoOfSteps)
{
  myStepper.step(-NoOfSteps);
  delay(100);
  //pushObject();
  myservo.write(0);                
  delay(1650);   
  myservo.write(180);  
  delay(1600);
  myservo.write(90);
  
  myStepper.step(NoOfSteps);
}
void pushObject()
{
  
  myservo.write(0);                
  delay(1650);   
  myservo.write(180);  
  delay(1600);
  myservo.write(90);
}
int countStep = 2090;//360*7;
char incoming =0;
void loop() {
  
   if(Serial.available()>0)
  {
    while(Serial.available()>0)
    {
      incoming = Serial.read();
      if(incoming == 'l'){ 
        countStep = countStep + 10;
        angle = 10;
        count = 0;
        Serial.println(countStep);
      }
    }
  }
  if(count == 0 && digitalRead(47) == LOW ){
  // step one revolution  in one direction:
  Serial.println("clockwise"); 
   
  delay(1000);
  
  Serial.println("First Floor");
  //pushObject();
  
  //delay(000);
  
  //goToFloor(1050);
//  
//  delay(3000);
//
  goToFloor(2090);
  
//
//  delay(3000);
//
//  goToFloor(2790);
//  
//  //countStep = countStep + 10;
  count =1;
  //delay(2000);
  }
  // step one revolution in the other direction:
 // Serial.println("counterclockwise");
  //myStepper.step(360*8);
  //delay(2000);
}

