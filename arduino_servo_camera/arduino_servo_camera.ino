//servo camera
//by aaron montoya-moraga
//project for sam lavigne's automating video class
//november 2018

//script for controlling a servo motor
//via a python script

//include servo library
#include <Servo.h>

//declare servos
Servo servoYaw;
Servo servoPitch;

//pins for servos
int pinYaw = 8;
int pinPitch = 9;

//current position of the servo
int currentYaw = 0;
int currentPitch = 0;

// step of servo
int deltaYaw = 1;
int deltaPitch = 1;

//step of time
int deltaTime = 5;

int incomingByte = 0;

String inputString = "";
boolean stringComplete = false;

void setup() {
  //begin serial communication
  Serial.begin(9600);
  //attach a pin to the yaw servo
  servoYaw.attach(pinYaw);
  //attach a pin to the pitch servo
  servoPitch.attach(pinPitch);
  //reserve 200 bytes for the inputString
  inputString.reserve(200);
}

void loop() {

  if (stringComplete) {
    Serial.println(inputString);
    moveYaw(inputString.toInt());
    delay(1);
    movePitch(inputString.toInt());
    delay(1);
    //clear
    inputString = "";
    stringComplete = false;
  }
}

//function for moving servo to desired yaw
void moveYaw(int desiredYaw) {

  //check if desiredPos is in range 0-180
  if (desiredYaw >= 0 && desiredYaw <= 180) {

    while (desiredYaw - currentYaw > deltaYaw) {
      currentYaw = currentYaw + deltaYaw;
      servoYaw.write(currentYaw);
    }
    while (desiredYaw - currentYaw < deltaYaw) {
      currentYaw = currentYaw - deltaYaw;
      servoYaw.write(currentYaw);
    }
  }
}

//function for moving servo to desired pitch
void movePitch(int desiredPitch) {

  //check if desiredPos is in range 0-180
  if (desiredPitch >= 0 && desiredPitch <= 180) {

    while (desiredPitch - currentPitch > deltaPitch) {
      currentPitch = currentPitch + deltaPitch;
      servoPitch.write(currentPitch);
    }
    while (desiredPitch - currentPitch < deltaPitch) {
      currentPitch = currentPitch - deltaPitch;
      servoPitch.write(currentPitch);
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
      stringComplete = true;
    }
  }
}


