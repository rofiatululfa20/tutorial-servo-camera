# servo_camera.py
# by aaron montoya-moraga
# november 2017

# import pyserial for writing serial to arduino
import serial
# import sys for retrieving arguments from commmand line
import sys
# import time for sleep function
import time

#configuration of arduino
arduinoPort = '/dev/cu.usbmodem1461'
arduinoBaudRate = 9600

# open the serial port, this resets the arduino
ser = serial.Serial(arduinoPort, arduinoBaudRate)

# wait two seconds so that arduino can reset

time.sleep(2)
while True:
    ser.write("0,0\n")#.encode('utf-8'))
    time.sleep(1)
    ser.write("90,90\n")
    time.sleep(1)
    ser.write("180,180\n")
    time.sleep(1)
    ser.write("90,90\n")
    time.sleep(1)

# infinite loop
# while True:

if (len(sys.argv) > 1):
    x = sys.argv[1]
    ser.write(b'90\n')
    # ser.write(x)
    print x

time.sleep(5)
ser.close()
