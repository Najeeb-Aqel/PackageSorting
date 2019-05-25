#include <KeyboardController.h>

// Initialize USB Controller
USBHost usb;
String tag = "";
// Attach Keyboard controller to USB
KeyboardController keyboard(usb);

void setup(){
  Serial.begin(9600);
}

void loop(){
  usb.Task();
}

void keyPressed() {
  char key = keyboard.getKey();
   if(key == 19)//control device stop transimission
   {
      Serial.print("Pressed:  ");
      Serial.print(tag);
      Serial.println();
      tag = "";
   }
   else
   {
      tag = tag + String(key);
   }
}

