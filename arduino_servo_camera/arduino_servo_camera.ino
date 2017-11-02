#include <Servo.h>

Servo rotation;

int counter = 0;

void setup() {
  Serial.begin(9600);
  rotation.attach(9);
}

void loop() {




}

//rotation.write(counter);
//
//delay(150);
//Serial.println(counter);
//
//counter = counter + 1;
//counter = counter % 180;
