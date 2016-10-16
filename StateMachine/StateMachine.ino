
void setup() {
  Serial.begin(9600);
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

void loop() { //Constantly try to read commands from the serial
  while (!Serial.available()){}
  char cmd = Serial.read();
  switch (cmd){
    default:
      break;
  }
}

SIGNAL(TIMER0_COMPA_vect){ //Every milli, check the states and perform tasks
  
}

void runPrint(){
  char ch = ' ';
  while (ch != ';'){
    while (!Serial.available()){}
    ch = Serial.read();
    Serial.print(ch);
  }
}
