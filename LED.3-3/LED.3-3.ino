const int analogPin=A0;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:

}

void loop() {
  int analogValue=analogRead(analogPin);
  Serial.println(analogValue);
  // put your main code here, to run repeatedly:

}
