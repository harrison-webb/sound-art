#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(6);
//tmrpcm.play("test.wav");

digitalWrite(3, HIGH);
digitalWrite(2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  tmrpcm.play("test.wav");
  delay(10000);
}
