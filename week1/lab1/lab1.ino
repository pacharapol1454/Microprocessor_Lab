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

void loop() {
  // put your main code here, to run repeatedly:
for (int i = 0; i <= 5; i++) {
      //DDRD=0xFF;
      PORTD = 0x04 << i; //0x02 0b0000 0010
      delay(1000);
    }
    PORTD = 0x00;
    for (int j = 0; j <= 1; j++) {
      //DDRB=0xFF;
      PORTB = 0x01 << j;
      delay(1000);
    }
    PORTB = 0x00;
  }
