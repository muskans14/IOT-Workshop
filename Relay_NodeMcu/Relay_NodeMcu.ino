#define BLYNK_TEMPLATE_ID   "TMPL3pOE0JnVO"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_PRINT Serial
#define BLYNK_auth "rmXv1MyTYR7jupRaPUwVDkQc8EDR6AOx"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "WIN-PN41CUFSF50 5492";
char pass[] = "socalled"; 

// Blynk auth token


// Relay pin
#define relayPin D1  // Relay connected to D1

// Blynk virtual pin handler
BLYNK_WRITE(V1) {
  int value = param.asInt();
  if (value == 1) {
    digitalWrite(relayPin, HIGH); // Relay ON
  } else {
    digitalWrite(relayPin, LOW);  // Relay OFF
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Start with relay OFF

  Blynk.begin(BLYNK_auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
