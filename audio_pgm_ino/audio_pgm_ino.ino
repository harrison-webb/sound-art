#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
const byte nano1 = 7;
const byte nano2 = 8;
const byte nano3 = 6;

const byte interruptPin = 2;
volatile byte state = LOW;
volatile bool startFlag = false;

void setup()
{
  startFlag = false;
  state = LOW;

  tmrpcm.speakerPin=9;

  Serial.begin(9600);

  if(!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  tmrpcm.setVolume(6);

  /* interrupt setup */
  pinMode(nano1, OUTPUT);
  pinMode(nano2, OUTPUT);
  pinMode(nano3, OUTPUT);

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(startFlag){
    tmrpcm.play("chrd.wav");
    delay(10909);
    // Serial.println("main 1");

    tmrpcm.stopPlayback();

    // Serial.println(startFlag);
    
    state = HIGH;
    digitalWrite(nano1, state);
    digitalWrite(nano2, state);
    digitalWrite(nano2, state);
    // delay(200);
  }
  // delay(2000);
  // Serial.println("i'm in the loop");

}

void blink() {
  startFlag = true;
    // Serial.println("startflag method");
}


