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
digitalWrite(trigPin,HIGH);
delayMicroseconds(500);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH); /*it starts counting number of microseconds until echoPin goes High &
                                  store that value to the variable duration,
                                   now this duration is then converted to the distance by the formula*/
distance = (duration/2)/29.1;
delay(200);
if(distance<25)
{
  tone(buzzled,980);
  count++;

  Serial.print("Distance = ");
Serial.print(distance);
Serial.print("cm");
Serial.println(" ");
Serial.print("Number of person = ");
Serial.print(count);
Serial.println(" ");
delay(500);
Serial.println(" ");
  {
 (!SD.begin(SD_ChipSelectPin));       //see if the card is present and can be initialized
                                  
  tmrpcm.setVolume(6);                    //0 to 7. Set volume level
  tmrpcm.play("5b.wav");         //the sound file "1" will play each time the arduino powers up, or is reset
  }
}
else
noTone(buzzled);
}
