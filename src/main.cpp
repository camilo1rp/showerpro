#include "Arduino.h"
const byte LED = 13;
const byte SENSOR = 52;
volatile int sensCnt = 0;
int Ltrs = 0;



void rutine () {
  sensCnt++;
}
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);
  attachInterrupt(SENSOR,rutine,RISING);
}

void loop() {
   analogWrite(LED,Ltrs);
   delay(20);
 if (sensCnt > 1000){
 Ltrs++;
 sensCnt = 0;
 }
if (Ltrs > 255){
  Ltrs = 0;
 }
 delay(20);
 Serial.println(sensCnt);
}
