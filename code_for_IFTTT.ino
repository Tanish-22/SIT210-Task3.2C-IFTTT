int led = 2;
#include <Arduino.h>
#include <hp_BH1750.h>  //  include the library
hp_BH1750 BH1750;       //  create the sensor

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  bool avail = BH1750.begin(BH1750_TO_GROUND);// init the sensor with address pin connetcted to ground
                                              // result (bool) wil be be "false" if no sensor found
}

void loop()
{
  // put your main code here, to run repeatedly:
  BH1750.start();   //starts a measurement
  float lux=BH1750.getLux();  //  waits until a conversion finished

  if(lux>300)
  {
    digitalWrite(led,HIGH);
  }

  else
  {
    digitalWrite(led,LOW);
  }

}
