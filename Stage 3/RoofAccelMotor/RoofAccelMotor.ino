


int PUL=7; //define Pulse pin
int DIR=6; //define Direction pin
int ENA=5; //define Enable Pin
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);

}

void loop() {
  for (int i=0; i<6400; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR,LOW);
    digitalWrite(ENA,HIGH);
    digitalWrite(PUL,HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL,LOW);
    delayMicroseconds(50);
  }
  for (int i=0; i<6400; i++)   //Backward 5000 steps
  {
    digitalWrite(DIR,HIGH);
    digitalWrite(ENA,HIGH);
    digitalWrite(PUL,HIGH);
    delayMicroseconds(50);
    digitalWrite(PUL,LOW);
    delayMicroseconds(50);
  }
}
//  #include <AccelStepper.h>
//AccelStepper stepperX(1, 4, 6);   // 1 = Easy Driver interface
//                                  // NANO Pin 4 connected to STEP pin of Easy Driver
//                                  // NANO Pin 6 connected to DIR pin of Easy Driver
//
//// Define the Pins used
//#define home_switch 9 // Pin 9 connected to Home Switch (MicroSwitch)
//
//// Stepper Travel Variables
//long TravelX;  // Used to store the X value entered in the Serial Monitor
//int move_finished=1;  // Used to check if move is completed
//long initial_homing=-1;  // Used to Home Stepper at startup
//
//
//void setup() {
//   Serial.begin(9600);  // Start the Serial monitor with speed of 9600 Bauds
//   
//   //pinMode(home_switch, INPUT_PULLUP);
//   
//   delay(5);  // Wait for EasyDriver wake up
//   
//
//   //  Set Max Speed and Acceleration of each Steppers at startup for homing
//  stepperX.setMaxSpeed(200.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
//  stepperX.setAcceleration(100.0);  // Set Acceleration of Stepper
// 
//
//// Start Homing procedure of Stepper Motor at startup
//
//  Serial.print("Stepper is Homing . . . . . . . . . . . ");
//
////  //while (digitalRead(home_switch)) {  // Make the Stepper move CCW until the switch is activated   
////    stepperX.moveTo(initial_homing);  // Set the position to move to
////    initial_homing--;  // Decrease by 1 for next move if needed
////    stepperX.run();  // Start moving the stepper
////    delay(5);
//////}
////
////  stepperX.setCurrentPosition(0);  // Set the current position as zero for now
////  stepperX.setMaxSpeed(100.0);      // Set Max Speed of Stepper (Slower to get better accuracy)
////  stepperX.setAcceleration(100.0);  // Set Acceleration of Stepper
////  initial_homing=1;
////
////  //while (!digitalRead(home_switch)) { // Make the Stepper move CW until the switch is deactivated
////    stepperX.moveTo(initial_homing);  
////    stepperX.run();
////    initial_homing++;
////    delay(5);
////  //}
////  
////  stepperX.setCurrentPosition(0);
////  Serial.println("Homing Completed");
////  Serial.println("");
////  stepperX.setMaxSpeed(1000.0);      // Set Max Speed of Stepper (Faster for regular movements)
////  stepperX.setAcceleration(1000.0);  // Set Acceleration of Stepper
////
////// Print out Instructions on the Serial Monitor at Start
////  Serial.println("Enter Travel distance (Positive for CW / Negative for CCW and Zero for back to Home): ");
//}
//
//void loop() {
//
// while (Serial.available()>0)  { // Check if values are available in the Serial Buffer
//
//  move_finished=0;  // Set variable for checking move of the Stepper
//  
//  TravelX= Serial.parseInt();  // Put numeric value from buffer in TravelX variable
//  if (TravelX < 0 || TravelX > 1350) {  // Make sure the position entered is not beyond the HOME or MAX position
//    Serial.println("");
//    Serial.println("Please enter a value greater than zero and smaller or equal to 1350.....");
//    Serial.println("");
//  } else {
//    Serial.print("Moving stepper into position: ");
//    Serial.println(TravelX);
//  
//  stepperX.moveTo(TravelX);  // Set new moveto position of Stepper
//  
//  delay(1000);  // Wait 1 seconds before moving the Stepper
//  }
//  }
//
//  if (TravelX >= 0 && TravelX <= 1350) {
//
//// Check if the Stepper has reached desired position
//  if ((stepperX.distanceToGo() != 0)) {
//    
//    stepperX.run();  // Move Stepper into position
//    
//  }
//
//// If move is completed display message on Serial Monitor
//  if ((move_finished == 0) && (stepperX.distanceToGo() == 0)) {
//    Serial.println("COMPLETED!");
//    Serial.println("");
//     Serial.println("Enter Travel distance (Positive for CW / Negative for CCW and Zero for back to Home): ");
//    move_finished=1;  // Reset move variable
//  }
//  }
//}
