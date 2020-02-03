int clock_pin = 13;//SHCP
int latch_pin = 10;//STCP
int data_pin = 11;//DS
int buttonLeft = A0;
int buttonRight = A1;
int c = 0 ;
void setup()
{
  pinMode(clock_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latch_pin,LOW);
  reg(0b00000110);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//1
  digitalWrite(latch_pin,LOW);
  reg(0b01011011);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//2
  digitalWrite(latch_pin,LOW);
  reg(0b01001111);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//3
  digitalWrite(latch_pin,LOW);
  reg(0b01100110);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//4
  digitalWrite(latch_pin,LOW);
  reg(0b01101101);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//5
  digitalWrite(latch_pin,LOW);
  reg(0b01111101);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//6
  digitalWrite(latch_pin,LOW);
  reg(0b00000111);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//7
  digitalWrite(latch_pin,LOW);
  reg(0b01111111);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//8
  digitalWrite(latch_pin,LOW);
  reg(0b01101111);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//9
  digitalWrite(latch_pin,LOW);
  reg(0b00111111);
  digitalWrite(latch_pin,HIGH);
  delay(1000);//0
}
