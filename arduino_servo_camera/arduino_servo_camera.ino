//servo camera
//by aaron montoya-moraga
//project for sam lavigne's automating video class
//november 2018

//script for controlling a servo motor
//via a python script

//include servo library
#include <Servo.h>

//declare servo
Servo myServo;

Servo otherServo;

//current position of the servo
int currentPos = 0;

// step of servo
int deltaPos = 1;

//step of time
int deltaTime = 5;

int incomingByte = 0;

String inputString = "";
boolean stringComplete = false;

void setup() {
  //begin serial communication
  Serial.begin(9600);
  //attach the servo to pin 9
  myServo.attach(9);
  //reserve 200 bytes for the inputString
  inputString.reserve(200);
}

void loop() {

  if (stringComplete) {
    Serial.println(inputString);
    moveTo(inputString.toInt());
    //clear
    inputString = "";
    stringComplete = false;
    
  }

  //  if (Serial.available() > 0) {
  //
  //
  //    incomingByte = Serial.read();
  //    Serial.print("i got ");
  //    Serial.println(incomingByte - '0', DEC);
  //  }

  //  rotation.write(counter);
  //rotation.write(incomingByte - '0');
  //  counter = counter + step;
  //  counter = counter % 180;
  //  delay(500);
  //  }

  //  moveTo(0);
  //  delay(1000);
  //  moveTo(90);
  //  delay(1000);
  //  moveTo(180);
  //  delay(1000);
  //  moveTo(90);
  //  delay(1000);


}

//function for moving servo to desired position
void moveTo(int desiredPos) {

  //check if desiredPos is in range 0-180
  if (desiredPos >= 0 && desiredPos <= 180) {

    //
    while (desiredPos - currentPos > deltaPos) {
      currentPos = currentPos + deltaPos;
      myServo.write(currentPos);
      delay(deltaTime);
    }
    while (desiredPos - currentPos < deltaPos) {
      currentPos = currentPos - deltaPos;
      myServo.write(currentPos);
      delay(deltaTime);
    }

  }
}

void serialEvent() {
  while (Serial.available()) {
    //get the new byte
    char inChar = (char)Serial.read();
    //add it to the inputString
    inputString = inputString + inChar;
    //if the incoming character is a new line, set a flag
    if (inChar == '\n') {
      //stringComplete = true;
      moveTo(random(0, 180));
    }
  }
}


