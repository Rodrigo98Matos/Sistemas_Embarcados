void espera_ms(volatile unsigned int m);
void espera_s(volatile unsigned int s);

volatile unsigned int i,j;
volatile char k;

  
void setup() {
  DDRB = 0b11100000;
  //Serial.begin(115200);

}

void loop() {
  volatile unsigned int i, j;
  for (unsigned char i = 0;i<=7;i++){
  PORTB = i;
  //Serial.print("MILISSEGUNDOS:\t");
  //unsigned long t = millis();
  espera_s(1);}
  //t = millis()-t;
  //Serial.println(t);
}

void espera_s(volatile unsigned int s){
  for(i=0;i<s;i++){
    for(j=0; j<14126; j++)
      for(k=0; k < 100; k++);
  }
}
void espera_ms(volatile unsigned int m){
  for(i=0;i<m;i++){
    for(j=0; j<14; j++)
      for(k=0; k < 101; k++);
  }
}
