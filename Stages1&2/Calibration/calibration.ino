
#include <HX711.h>

/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 5 -> HX711 CLK
 Arduino pin 6 -> HX711 DOUT
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/


HX711 scale;

float calibration_factor = 404.152; // this calibration factor is adjusted according to my load cell
float units;
void setup() {
  Serial.begin(9600);
  scale.begin(8,9);
  scale.set_scale(calibration_factor);
  scale.tare();  //Reset the scale to 0
}

void loop() {


  Serial.print("Reading: ");
  units = scale.get_units(),10 ;
  if (units < 0)
  {
    units = 0.00;
  }
  //units = units * 0.035274;
  Serial.print(units);
  Serial.println(" grams"); 
}
