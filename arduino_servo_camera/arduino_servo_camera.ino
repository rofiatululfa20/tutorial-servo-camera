//servo camera
//by aaron montoya-moraga
//project for sam lavigne's automating video class
//november 2018

//script for controlling servo motors with arduino
//via python script with pyserial module

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

//store of input
String inputYaw = "";
String inputPitch = "";

//flag for input being ready
boolean readyYaw = false;
boolean readyPitch = false;

void setup() {

  //begin serial communication
  Serial.begin(9600);

  //attach a pin to the yaw servo
  servoYaw.attach(pinYaw);
  //attach a pin to the pitch servo
  servoPitch.attach(pinPitch);

  //reserve 200 bytes for the inputs
  inputYaw.reserve(200);
  inputPitch.reserve(200);
}

void loop() {

  //if both inputs 
  if (readyYaw && readyPitch) {

    //move yaw
    moveYaw(inputYaw.toInt());
    delay(1);

    //move pitch
    movePitch(inputPitch.toInt());
    delay(1);

    //clear input
    inputYaw = "";
    inputPitch = "";
    readyYaw = false;
    readyPitch = false;   
  }
}

//function for moving servo to desired yaw
void moveYaw(int desiredYaw) {

  //check range 0-180
  if (desiredYaw >= 0 && desiredYaw <= 180) {

    //move in one direction
    while (desiredYaw - currentYaw > deltaYaw) {
      currentYaw = currentYaw + deltaYaw;
      servoYaw.write(currentYaw);
    }

    //or move in the other direction
    while (desiredYaw - currentYaw < deltaYaw) {
      currentYaw = currentYaw - deltaYaw;
      servoYaw.write(currentYaw);
    }
  }
}

//function for moving servo to desired pitch
void movePitch(int desiredPitch) {

  //check range 0-180
  if (desiredPitch >= 0 && desiredPitch <= 180) {

    //move in one direction
    while (desiredPitch - currentPitch > deltaPitch) {
      currentPitch = currentPitch + deltaPitch;
      servoPitch.write(currentPitch);
    }

    //or move in the other direction
    while (desiredPitch - currentPitch < deltaPitch) {
      currentPitch = currentPitch - deltaPitch;
      servoPitch.write(currentPitch);
    }
  }
}

//function triggered everytime there is a serial event
void serialEvent() {
  while (Serial.available()) {
    //get the new char
    char inChar = (char)Serial.read();

    //check if char is new line
    if (inChar == '\n') {
      readyYaw = true;
      readyPitch = true;
    }

    //if char is comma and yaw is not ready
    if (inChar == ',' && !readyYaw) {
      readyYaw = true;
      readyPitch = false;
    }

    //append newChar to the corresponding input
    if (!readyYaw) {
      inputYaw = inputYaw + inChar;
    }
    if (!readyPitch) {
      inputPitch = inputPitch + inChar;
    }
  }
}


