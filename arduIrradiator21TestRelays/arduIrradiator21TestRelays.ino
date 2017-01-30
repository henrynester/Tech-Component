const byte farLightRelayPin = 7;
const byte nearLightRelayPin = 5;
const byte heaterRelayPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(farLightRelayPin, OUTPUT);
  pinMode(nearLightRelayPin, OUTPUT);
  pinMode(heaterRelayPin, OUTPUT);
}

void loop() {
  digitalWrite(farLightRelayPin, HIGH);
  digitalWrite(nearLightRelayPin, LOW);
  digitalWrite(heaterRelayPin, LOW);
  delay(5000);
  digitalWrite(farLightRelayPin, LOW);
  digitalWrite(nearLightRelayPin, HIGH);
  digitalWrite(heaterRelayPin, LOW);
  delay(5000);
  digitalWrite(farLightRelayPin, LOW);
  digitalWrite(nearLightRelayPin, LOW);
  digitalWrite(heaterRelayPin, HIGH);
  delay(5000);
}
