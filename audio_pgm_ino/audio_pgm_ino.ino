#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
const byte nano1 = 7;
const byte nano2 = 8;

const byte interruptPin = 2;
// const byte interruptPin2 = 3;
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

  /* interrupt setup */
  pinMode(nano1 , OUTPUT);
  pinMode(nano2 , OUTPUT);

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  tmrpcm.play("chrd.wav");
  delay(10909);
  Serial.println("speaker 1");

  tmrpcm.stopPlayback();
  // delay(1000);
}

void blink() {
  state = !state;
  // digitalWrite(ledPin, state);
  digitalWrite(nano1, state);
  digitalWrite(nano2, state);
}


