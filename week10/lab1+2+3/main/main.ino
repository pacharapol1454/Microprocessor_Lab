#define MOTOR_D1_PIN 7
#define MOTOR_D2_PIN 8
#define MOTOR_PWM_PIN 9
int val=0;
int i=0;
int j=0;
bool EN_Ac = false;
bool EN_Ap = false;
bool EN_Bc = false;
bool EN_Bp = false;
void setSpeed() {
  while(Serial.available()==0){}
  val = Serial.parseInt();
  if(val>=0&&val<=255){
    digitalWrite(7,1);
    digitalWrite(8,0);
    digitalWrite(9,val);
  }
  if(val<0&&val>=-255){
    digitalWrite(7,0);
    digitalWrite(8,1);
    digitalWrite(9,-val);
  }
}
void setup() {
  pinMode(MOTOR_D1_PIN,OUTPUT);
  pinMode(MOTOR_D2_PIN,OUTPUT);
  pinMode(MOTOR_PWM_PIN,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), encoderCheck, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), encoderCheck, FALLING);
  Serial.begin(9600);
}
void encoderHandle(bool isCW){
  if(isCW){
    i++;
    j++;
  }
  else{
    i--;
  }
  Serial.println("Counter:");
  Serial.println(i);
  Serial.println("Direction");
  if(j!=0){
    Serial.println("CW");
  }
  else{
    Serial.println("CCW");
  }
}
void encoderCheck(){
  EN_Ac = !digitalRead(2);
  EN_Bc = !digitalRead(3);
  if(EN_Ac&&EN_Bc){
    if(EN_Ap&&!EN_Bp){
      encoderHandle(1);
    }
    else if(!EN_Ap&&EN_Bp){
      encoderHandle(0);
    }
    }
  EN_Ap = EN_Ac;
  EN_Bp = EN_Bc;
}
void loop(){
}
