
int clock_pin = 13;//SHCP
int latch_pin = 10;//STCP
int data_pin = 11;//DS
int c = 0;
int left_btn = A0; 
int right_btn = A1; 
int number = 0;
uint8_t num[]= {0b00000000,0b00000110,01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
void setup()
{
  pinMode(clock_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  pinMode(left_btn,INPUT);
  pinMode(right_btn,INPUT);
  Serial.begin(9600);
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
int i = 0;
void loop(){
  int goRight = digitalRead(right_btn);
  int goLeft = digitalRead(left_btn);
  
  if(goRight==0){
    i=i+1;
    Serial.println("goRight");
  }
  if(goLeft==0&&i==0){
    i=9;
    Serial.println("goLeft");
  }
  else if(goLeft==0&&i!=0){
    i=i-1;
  }
  digitalWrite(latch_pin,LOW);
  reg(num[i]);
  digitalWrite(latch_pin,HIGH);
  Serial.println("this is num");
  Serial.println(i);
  Serial.println(num[i]);
  Serial.println("this is button status");
  Serial.println(digitalRead(left_btn));
  Serial.println(digitalRead(right_btn));
  delay(1500);
  
    
}
/*  digitalWrite(latch_pin,LOW);
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
  delay(1000);//0*/
