

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "esp8266-and-firebase.firebaseio.com"
#define FIREBASE_AUTH "14tvRbbGymyoWr6WSvvxXxW5qWgplizKd1MHLfVk"
#define WIFI_SSID "Mohandesoon"
#define WIFI_PASSWORD "2380455na3na3"
String LEDStatus = "";

void setup() {

pinMode(LED_BUILTIN,OUTPUT);
//pinMode(D2,INPUT);
pinMode(D3,INPUT);
pinMode(D4,OUTPUT);

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

//Firebase.setString("TestGP/box1/BoxNo","\"2103\"");
//Firebase.setString("TestGP/box1/City","\"Nablus\"");
//Firebase.setString("TestGP/box1/Weight","\"115.6\"");
//Firebase.setString("TestGP/box1/PersonId","\"556\"");
//Firebase.setInt("TestGP/box1/1_RoofNo",1);
}
struct box{
  String boxNo;
  String city;
  String weight;
  String PersonId;
  bool isEmpty;
  bool isOpen;
  int roofNo;
};

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
struct box getBox(int i)
{
  String temp = "BoxGP/box_" + String(i) + "/" ;
  struct box newBox ;
  newBox.boxNo = Firebase.getString(temp + "BoxNo");
  newBox.city = Firebase.getString(temp + "City");
  newBox.weight = Firebase.getString(temp + "Weight");
  newBox.PersonId = Firebase.getString(temp + "PersonId");
  newBox.isEmpty = Firebase.getBool(temp + "Empty");
  newBox.isOpen = Firebase.getBool(temp + "Open");
  newBox.roofNo = Firebase.getInt(temp + "RoofNo");
  return newBox;
}

void checkBoxStatus(int BoxNo)
{
  //check if there is object 
  bool isBox;
  //check if Door is open 
  bool isOpen;
  if(isBox)
  {
    if(isOpen)
    {
      //set Empty: false, Open:true
    }
    else
    {
      //set Empty: false, Open:false
    }
  }
  else
  {
    if(isOpen)
    {
      //set Empty: false, Open:true
    }
    else
    {
      //set Empty: true, Open:false
    }
  }
  
}

void setEmail()
{
  Firebase.setString("EmailGP/2022","wajdi1077@gmail.com");
  Firebase.setString("EmailGP/6062","rashad--2013@hotmail.com");
  Firebase.setString("EmailGP/5542","wajdi.mabroukeh@stu.najah.edu");
}

void checkLocalBoxes()
{
  //check box one
   
  
}
int i =1;
bool empty = false;
void loop() {
i=i+1;
if(i>4)
i=1;
setEmail();
setBox(i);
//empty = !empty; 
//Firebase.setBool("TestGP/box1/1_Empty",empty);
LEDStatus = Firebase.getString("Sorter/LEDStatus");
LEDStatus.replace("\"", "");
Serial.println(LEDStatus.toInt());
if(LEDStatus.toInt() == 1)

{

digitalWrite(LED_BUILTIN,HIGH);

}

else

{

digitalWrite(LED_BUILTIN,LOW);

}

if (Firebase.failed()) // Check for errors 
{

Serial.print("setting /number failed:");

Serial.println(Firebase.error());
delay(1000);
return;

}

delay(1000);

}


