
int clock_pin = 13;//SHCP
int latch_pin = 10;//STCP
int data_pin = 11;//DS
int c = 0;
void setup()
{
  pinMode(clock_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
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

void reg(uint8_t updata){
  for(int i=0;i<8;i++){
     digitalWrite(data_pin,(updata>>7-i & 0b00000001));
     digitalWrite(clock_pin,HIGH);
     digitalWrite(clock_pin,LOW);
     Serial.println(updata);
     Serial.println("void reg end");
  }
}
void loop(){
  if(c==16){
    c=0;
  }
  else{
  digitalWrite(latch_pin,LOW);
  reg(0b1000000000000000>>c);
  Serial.println("LATCH HIGH");
  digitalWrite(latch_pin,HIGH);
  c++;
  //to reverse direction, change >> to << and 1000.. to ..0001
  }
}
