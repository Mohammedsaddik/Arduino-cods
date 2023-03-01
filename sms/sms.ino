int X=13;
void setup() {
pinMode(X, OUTPUT);
}
void loop() {
digitalWrite(X, HIGH);
delay(1000);
digitalWrite(X, LOW);
delay(1000);
}
