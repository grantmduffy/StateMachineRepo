
//State Types
typedef enum {
  
} ;

//States
bool ledOn;

void setup() {
  Serial.begin(9600);
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);

  //Initial States
  ledOn = false;
}

void loop() { //Constantly try to read commands from the serial
  while (!Serial.available()){}
  char cmd = Serial.read();
  switch (cmd){
    case ';':
      break;
    case 'P':
      runPrint();
      break;
    case 'L':
      runSetLed();
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

void runSetLed(){
  while (!Serial.available()){}
  char ch = Serial.read();
  switch (ch){
    case ';':
      break;
    case '0':
      ledOn = false;
      break;
    case '1':
      ledOn = true;
      break;
  }
}

