const int analogPin = A0;
const int ledCount = 10;
int ledPins[]={
  2,3,4,5,6,7,8,9,10,11
};

void setup() {
  Serial.begin(9600);
  for (int thisLed = 0; thisLed < ledCount; thisLed++){
    pinMode(ledPins[thisLed],OUTPUT);
  }
}

void loop() {
  int sensorValue = analogRead(analogPin);
  if (sensorValue < 700){
    sensorValue = 700;
  }
  else if (sensorValue > 900){
    sensorValue = 900;
  }
  int ledLevel = map(sensorValue, 700, 900, 0, ledCount);
  for (int thisLed = 0; thisLed < ledCount; thisLed++){
    if(thisLed < ledLevel){
      digitalWrite(ledPins[thisLed],HIGH);
    }
    else{
      digitalWrite(ledPins[thisLed],LOW);
    }
  }
  Serial.println(sensorValue);
  delay(1);
}
