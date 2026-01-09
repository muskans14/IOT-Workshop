#define trigPin 9
#define echoPin 10
#define relayPin 7
#define potPin A0

long duration;
int distance;
int potValue;
int threshold;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Read potentiometer (0–1023)
  potValue = analogRead(potPin);

  // Map pot to distance threshold (5–50 cm)
  threshold = map(potValue, 0, 1023, 5, 50);

  // Ultrasonic trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Threshold: ");
  Serial.print(threshold);
  Serial.println(" cm");

  // Relay control
  if (distance > 0 && distance < threshold) {
    digitalWrite(relayPin, HIGH); // Relay ON
  } else {
    digitalWrite(relayPin, LOW);  // Relay OFF
  }

  delay(100);
}
