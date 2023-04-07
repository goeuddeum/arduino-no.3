const int buttonPin = 5;  // the pin that the pushbutton is attached to
const int ledPin = 6;    // the pin that the LED is attached to

int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button

int buzzer=7;
int numTones = 8;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392};
void setup() {

  pinMode(buttonPin, INPUT);

  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
}


void loop() {
  buttonState = digitalRead(buttonPin);


  if (buttonState != lastButtonState) {
 
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
  
      Serial.println("off");
    }
 
    delay(50);
  }
  
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0) {
    digitalWrite(ledPin, LOW);
     noTone(buzzer);
  } else {
    digitalWrite(ledPin, HIGH);
    for(int i = 0; i < numTones; i++)
  {
    tone(buzzer, tones[i]);
    delay(50);
  }
  }
}
