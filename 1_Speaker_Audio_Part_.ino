     // Full code is not added.
           /*Defence Entrance Security System*/           
                      //Audio Part


#include <SD.h>                           //include SD module library
#include <TMRpcm.h>                       //include speaker control library

#define SD_ChipSelectPin 4                //define CS pin
                                          //cs-4(53),sck-13(52),mosi-11(51),miso-12(50)
TMRpcm tmrpcm;

//initialize the pins
const int trigPin = 6;   
const int echoPin = 5;   
const int buzzled = 7;
int count = 0;

//initialize the variables
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(buzzled,OUTPUT);

 tmrpcm.speakerPin = 9;             //define speaker pin.                                       
 Serial.begin(9600);
  
}

void loop() 
{
}
