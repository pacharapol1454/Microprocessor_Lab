#include<stdio.h>
void setup()
{
  Serial.begin(9600);
  DDRC = 0x00;
  DDRD = 0xFF;
  DDRB = 0xFF;
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}
void loop()
{
  int t=0;
  analogRead(A2);
  t=A2;
  
  int Left = 0, Right = 0;
  //  ((PINC >> 0) & 0x01);
  digitalRead(A0);
  if (((PINC >> 0) & 0x01)) {
    Left = 1;
  }
  else if(((PINC >> 1) & 0x01)) {
    Left = 0;
  }
  Serial.println(Left);
  //  while(1){
  if (Left == 1) {
    for (int i = 0; i <= 5; i++) {
      //DDRD=0xFF;
      PORTD = 0x04 << i; //0x02 0b0000 0010
      delay(t);
      Serial.println(Left);
    }
    PORTD = 0x00;
    for (int j = 0; j <= 1; j++) {
      //DDRB=0xFF;
      PORTB = 0x01 << j;
      delay(t);
      Serial.println(Left);
    }
    PORTB = 0x00;
  }
  else {
    for (int j = 1; j >= 0; j--) {
      //DDRB=0xFF;
      PORTB = 0x01 << j;
      delay(t);
      Serial.println(Left);
    }
    PORTB = 0x00;

    for (int i = 5; i >= 0; i--) {
      //DDRD=0xFF;
      PORTD = 0x04 << i; //0x02 0b0000 0010
      delay(t);
      Serial.println(Left);
    }
    PORTD = 0x00;
  }

}
