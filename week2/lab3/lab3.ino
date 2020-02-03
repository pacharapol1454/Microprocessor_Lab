
int clock_pin = 13;//SHCP
int latch_pin = 10;//STCP
int data_pin = 11;//DS
int left_btn = A0;
int right_btn = A1;
int lag_pin = A2;
uint16_t pos=0b0000000000000001;
void setup()
{
  pinMode(clock_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  pinMode(left_btn,INPUT);
  pinMode(right_btn,INPUT);
  pinMode(lag_pin,INPUT);
  Serial.begin(9600);
}

void reg(uint16_t updata){
  for(int i=0;i<16;i++){
     digitalWrite(data_pin,(updata>>15-i & 0b0000000000000001));
     digitalWrite(clock_pin,HIGH);
     digitalWrite(clock_pin,LOW);
     Serial.println(updata);
     Serial.println("void reg end");
  }
}
int c=0;
void loop(){
  int moveL = digitalRead(left_btn);
  int moveR = digitalRead(right_btn);
  int lag = analogRead(lag_pin);
  digitalWrite(latch_pin,LOW);
  if(moveL==0){
    if(c==16){
      c=0;
    }
    else{
    reg(0b0000000000000001<<c);
    c++;
      delay(lag);
    }
      if(moveL==0){
    if(c==16){
      c=0;
    }
    else{
    reg(0b1000000000000000>>c);
    c++;
      delay(lag);
    }
}
