#include <Arduino.h>

#define LED_LEFT 2
#define LED_RIGHT 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World");
  delay(1000);
}
