

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "esp8266-and-firebase.firebaseio.com"
#define FIREBASE_AUTH "14tvRbbGymyoWr6WSvvxXxW5qWgplizKd1MHLfVk"
#define WIFI_SSID "****"
//Mohandesoon
#define WIFI_PASSWORD "****"
//2380455na3na3
#define Box1Door D5
#define Box2Door D4
#define Box3Door D3
#define Box1Exist D7
#define Box2Exist D6
#define Box3Exist D8
#define Box1Lock D0
#define Box2Lock D2
#define Box3Lock D1


struct box{ 
  bool isEmpty;
  bool isOpen;
//  bool isOpenChanged;
//  bool isEmptyChanged;
};
struct box boxes[3];

void setupBoxesFirebase()
{
  
}

void setupLocalBoxes()
{
  boxes[0].isEmpty = false;
  boxes[0].isOpen = false;
  
  boxes[1].isEmpty = false;
  boxes[1].isOpen = false;
  
  boxes[2].isEmpty = false;
  boxes[2].isOpen = false;  
}
void setup() {

setupLocalBoxes();
Serial.begin(9600);
//Boxes Door
pinMode(Box1Door,INPUT);
pinMode(Box2Door,INPUT);
pinMode(Box3Door,INPUT);
//Boxes Exist
pinMode(Box1Exist,INPUT);
pinMode(Box2Exist,INPUT);
pinMode(Box3Exist,INPUT);
//Boxes Locker
pinMode(Box1Lock,OUTPUT);
pinMode(Box2Lock,OUTPUT);
pinMode(Box3Lock,OUTPUT);


digitalWrite(LED_BUILTIN,LOW);

Serial.begin(9600);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) {

Serial.print(".");

delay(500);

}

Serial.println();

Serial.print("connected: ");

Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}




void setBox(int i)
{
  String temp = "BoxGP/box_" + String(i) + "/" ;
  Firebase.setString(temp + "BoxNo","2103");
  Firebase.setString(temp + "City","Nablus");
  Firebase.setString(temp + "Weight","115.6");
  Firebase.setString(temp + "PersonId","556");
  Firebase.setBool(temp + "Empty",false);
  Firebase.setBool(temp + "Open",false);
  Firebase.setInt(temp + "RoofNo",i);
}
void setEmail()
{
  Firebase.setString("EmailGP/2022","wajdi1077@gmail.com");
  Firebase.setString("EmailGP/6062","rashad--2013@hotmail.com");
  Firebase.setString("EmailGP/5542","wajdi.mabroukeh@stu.najah.edu");
}
//struct box getBox(int i)
//{
//  String temp = "BoxGP/box_" + String(i) + "/" ;
//  struct box newBox ;
//  newBox.boxNo = Firebase.getString(temp + "BoxNo");
//  newBox.city = Firebase.getString(temp + "City");
//  newBox.weight = Firebase.getString(temp + "Weight");
//  newBox.PersonId = Firebase.getString(temp + "PersonId");
//  newBox.isEmpty = Firebase.getBool(temp + "Empty");
//  newBox.isOpen = Firebase.getBool(temp + "Open");
//  newBox.roofNo = Firebase.getInt(temp + "RoofNo");
//  return newBox;
//}

bool isBoxExist(int BoxNo)
{
  if(BoxNo == 1)
  {
    if(digitalRead(Box1Exist) == LOW)
      return true;
    else
      return false;
  }
  else if(BoxNo == 2)
  {
    if(digitalRead(Box2Exist) == LOW)
      return true;
    else
      return false;
  }
  else if(BoxNo == 3)
  {
    if(digitalRead(Box3Exist) == LOW)
      return true;
    else
      return false;
  }
  else
  {
      return false;
  }  
}

bool isBoxDoorOpen(int BoxNo)
{
  if(BoxNo == 1)
  {
    if(digitalRead(Box1Door) == HIGH)
      return true;
    else
      return false;
  }
  else if(BoxNo == 2)
  {
    if(digitalRead(Box2Door) == HIGH)
      return true;
    else
      return false;
  }
  else if(BoxNo == 3)
  {
    if(digitalRead(Box3Door) == HIGH)
      return true;
    else
      return false;
  }
  else
  {
      return false;
  }  
}

void checkAllBoxStatus()
{
  checkBoxStatus(1);
  checkBoxStatus(2);
  checkBoxStatus(3);
}
void checkBoxStatus(int BoxNo)
{
  // Firebase Box Path 
  String temp = "BoxGP/box_" + String(BoxNo) + "/" ;
  //check if there is object 
  bool isBox = isBoxExist(BoxNo);
  //check if Door is open 
  bool isOpen = isBoxDoorOpen(BoxNo);
  if(isBox)
  {
    if(isOpen)
    {
      //set Empty: false, Open:true
      boxes[BoxNo-1].isEmpty = false;
      boxes[BoxNo-1].isOpen = true; 
      Firebase.setBool(temp + "Empty",false);
      Firebase.setBool(temp + "Open",true);
    }
    else
    {
      //set Empty: false, Open:false
      boxes[BoxNo-1].isEmpty = false;
      boxes[BoxNo-1].isOpen = false; 
      Firebase.setBool(temp + "Empty",false);
      Firebase.setBool(temp + "Open",false);
    }
  }
  else
  {
    if(isOpen)
    {
      //set Empty: false, Open:true
      boxes[BoxNo-1].isEmpty = false;
      boxes[BoxNo-1].isOpen = true;
      Firebase.setBool(temp + "Empty",false);
      Firebase.setBool(temp + "Open",true);
    }
    else
    {
      //set Empty: true, Open:false
      boxes[BoxNo-1].isEmpty = true;
      boxes[BoxNo-1].isOpen = false;
      Firebase.setBool(temp + "Empty",true);
      Firebase.setBool(temp + "Open",false);
    }
  }
  
}



void openBoxDoor(int BoxNo)
{
  if(BoxNo == 1)
  {
    digitalWrite(Box1Lock, HIGH);
  }
  else if(BoxNo == 2)
  {
    digitalWrite(Box2Lock, HIGH);
  }
  else if(BoxNo == 3)
  {
    digitalWrite(Box3Lock, HIGH);
  }
}

void closeBoxDoor(int BoxNo)
{
  if(BoxNo == 1)
  {
    digitalWrite(Box1Lock, LOW);
  }
  else if(BoxNo == 2)
  {
    digitalWrite(Box2Lock, LOW);
  }
  else if(BoxNo == 3)
  {
    digitalWrite(Box3Lock, LOW);
  }
}

void checkLocalBoxes()
{
  // Firebase Box Path 
  String temp = "BoxGP/box_" + String(1) + "/" ;
  bool isBox1Open = Firebase.getBool(temp + "Open");
  temp = "BoxGP/box_" + String(2) + "/" ;
  bool isBox2Open = Firebase.getBool(temp + "Open");
  temp = "BoxGP/box_" + String(3) + "/" ;
  bool isBox3Open = Firebase.getBool(temp + "Open");
  //check box one
  if(isBox1Open == true && boxes[0].isOpen != isBox1Open)
    openBoxDoor(1);
  //check box two
  if(isBox2Open == true && boxes[1].isOpen != isBox2Open)
    openBoxDoor(2);
  //check box three
  if(isBox3Open == true && boxes[2].isOpen != isBox3Open)
    openBoxDoor(3);
    
  delay(3000); // open door for 3 seconds   
  
  //check box one  
  if(isBox1Open == true && boxes[0].isOpen != isBox1Open)
  {
    closeBoxDoor(1);
    boxes[0].isOpen = true;
  }    
  //check box two
  if(isBox2Open == true && boxes[1].isOpen != isBox2Open)
  {
    closeBoxDoor(2);
    boxes[1].isOpen = true;
  }    
  //check box three
  if(isBox3Open == true && boxes[2].isOpen != isBox3Open)
  {
    closeBoxDoor(3);
    boxes[2].isOpen = true;
  } 
  
}

bool flag =false;
void loop() {

checkAllBoxStatus();
checkLocalBoxes();
Serial.println("Box_1_Empty:" + boxes[0].isEmpty?"Win":"Lose");
Serial.println("Box_2_Empty:" + boxes[1].isEmpty?"Win":"Lose");
Serial.println("Box_3_Empty:" + boxes[2].isEmpty?"Win":"Lose");
if(flag)
{
  digitalWrite(Box2Lock, LOW);

}
else
{
    digitalWrite(Box2Lock, HIGH);

}
flag=!flag;
if (Firebase.failed()) // Check for errors 
{

Serial.print("setting /number failed:");

Serial.println(Firebase.error());
delay(1000);
return;

}

delay(1000);

}


