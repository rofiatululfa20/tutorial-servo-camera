import serial
import sys

# serial.tools.list_ports.comports()

# ser = serial.Serial('/dev/tty.usbserial', 9600)

ser = serial.Serial('/dev/cu.usbmodem1461', 9600)

ser.write('5')

if (len(sys.argv) > 1):
    print sys.argv[1]
