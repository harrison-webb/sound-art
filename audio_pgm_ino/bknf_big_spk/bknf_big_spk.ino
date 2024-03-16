#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

const byte interruptPin = 2;
volatile byte state = LOW;

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

  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(state)
    {
    tmrpcm.play("bknf.wav"); //big speaker

    delay(10909);
    Serial.println("speaker 1");

    tmrpcm.stopPlayback();
    }
}

void blink() {
  state = !state;
}


