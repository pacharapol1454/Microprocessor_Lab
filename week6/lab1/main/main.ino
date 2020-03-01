#include <Arduino.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); //IO,CLK,CE
RtcDS1302<ThreeWire>Rtc(myWire);
const int ledPin = 3;
int printDateTime(const RtcDateTime& dt){ 
return dt.Second();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Rtc.Begin();
  //year month date hr min sec
  RtcDateTime setting_time(2020,2,28,18,0,0);
  printDateTime(setting_time);
}



void loop() {
  //put your main code here, to run repeatedly:
  RtcDateTime now = Rtc.GetDateTime();
  int Second = printDateTime(now);
  if ((Second%2) == 0){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  } 
}
