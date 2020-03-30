#define MOTOR_D1_PIN 7
#define MOTOR_D2_PIN 8
#define MOTOR_PWM_PIN 9
void setup() {
  pinMode(MOTOR_D1_PIN,OUTPUT);
  pinMode(MOTOR_D2_PIN,OUTPUT);
  pinMode(MOTOR_PWM_PIN,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
}
int val=0;

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
void loop(){
  setSpeed();
  Serial.println(val);
}
