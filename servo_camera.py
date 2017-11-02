# by aaron montoya-moraga
# november 2017

# import pyserial for writing serial to arduino
import serial
# import sys for retrieving arguments from commmand line
import sys
# import time for sleep function
import time

arduinoPort = '/dev/cu.usbmodem1461'
arduinoBaudRate = 9600


ser = serial.Serial(arduinoPort, arduinoBaudRate)
print(ser.name)
time.sleep(5)
ser.write("5\n")#.encode('utf-8'))

# infinite loop
while True:



if (len(sys.argv) > 1):
    x = sys.argv[1]
    ser.write(b'90\n')
    # ser.write(x)
    print x

time.sleep(5)
ser.close()
