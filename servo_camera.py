# servo_camera.py
# by aaron montoya-moraga
# november 2017

# script for controlling servo motors with arduino
# via python script with pyserial module

# import pyserial for writing serial to arduino
import serial
# import time for sleep function
import time

# configuration of arduino
arduinoPort = '/dev/cu.usbmodem1461'
arduinoBaudRate = 9600

# open the serial port, this resets the arduino
ser = serial.Serial(arduinoPort, arduinoBaudRate)

# wait so that arduino can reset
time.sleep(2)

#delta of time, in seconds
deltaTime = 0.5

# infinite loop
while True:
    #write on serial port
    ser.write("0,0\n")
    time.sleep(deltaTime)
    ser.write("90,90\n")
    time.sleep(deltaTime)
    ser.write("180,180\n")
    time.sleep(deltaTime)
    ser.write("90,90\n")
    time.sleep(deltaTime)

# wait
time.sleep(2)

# close the serial port
ser.close()
