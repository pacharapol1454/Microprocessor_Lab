
int clock_pin = 13;//SHCP
int latch_pin = 10;//STCP
int data_pin = 11;//DS
int left_btn = A0;
int right_btn = A1;
uint16_t pos=0b0000000000000001;
void setup()
{
  pinMode(clock_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  pinMode(left_btn,INPUT);
  pinMode(right_btn,INPUT);
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
  digitalWrite(latch_pin,LOW);
  reg(pos);
  while(moveL == 1 || moveR == 1){
    Serial.println("in while loop");
    delay(1000);
    if(moveR == 0 && c == 15){
      pos=0b1000000000000000;
      c=0;
      Serial.println("moveR1");
    }
    else if(moveR == 0){
      reg(pos>>c);
      c++;
            Serial.println("moveR2");
    }
    if(moveL == 0 && c == 0){
      pos=0b0000000000000001;
      c=15;
            Serial.println("moveL1");
    }
    else if(moveL == 0){
      pos<<1;
      c--;
            Serial.println("moveL2");
    }
      Serial.println(pos);
      Serial.println(moveL);
      Serial.println(moveR);
      Serial.println("end while");
    delay(1000);
  }

      Serial.println("exit while");  
  digitalWrite(latch_pin,HIGH);
  delay(500);
}
