void setup() {
  pinMode(11, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  int sw=digitalRead(11);
  Serial.println(sw+1);
  delay(1000);
}