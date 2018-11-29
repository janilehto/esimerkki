#define S1 11
#define PRESSED LOW
#define RELEASED HIGH

int S1State;
void setup() {
  pinMode(S1, INPUT_PULLUP);
  S1State = digitalRead(S1);
  Serial.begin(9600);
}
#define FILTER 20
int buttonIsPressed(){
  int x = digitalRead(S1);
  int ret = 0;
  if(x == PRESSED && S1State == RELEASED){
    ret = 1;
    delay(FILTER);
  }
  S1State = x;
  return ret;
}
void loop() {
  if(buttonIsPressed()){
    Serial.println("Button is pressed");
  }
}
