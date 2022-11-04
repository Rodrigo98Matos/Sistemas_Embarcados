void espera_ms(volatile unsigned int m);
void espera_s(volatile unsigned int s);

volatile unsigned int i,j;
volatile char k;

  
void setup() {
  DDRB |= (1<<5);
  Serial.begin(115200);

}

void loop() {
  volatile unsigned int i, j;
  PORTB ^= (1<<5);
  Serial.print("MILISSEGUNDOS:\t");
  unsigned long t = millis();
  espera_ms(1000);
  t = millis()-t;
  Serial.println(t);
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
