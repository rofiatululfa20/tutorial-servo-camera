# servo_camera

![02_final](https://github.com/montoyamoraga/servo_camera/blob/master/pics/02_final.jpg "servo_camera")

## About

This project by [Aarón Montoya-Moraga](http://montoyamoraga.io/) consists of a webcam on servos that can be controlled from a Python script.

Developed for [Sam Lavigne](http://lav.io/)'s [Automating video](https://github.com/antiboredom/automating-video-itp) class, at [New York University](http://www.nyu.edu/)'s [Interactive Telecommunications Program](https://tisch.nyu.edu/itp), November 2017.

## Environment

This project was programmed and tested using the following software and hardware:

* Macbook running macOS High Sierra
* Arduino Uno
* Arduino IDE 1.8.3
* Python 2.7.10
* [virtualenv](https://virtualenv.pypa.io/en/stable/) 15.1.0 Python module
* [pyserial](https://github.com/pyserial/pyserial) Python module

## Code

* Arduino script to receive commands from the Python script.
* Python script to send commands to Arduino.

## Materials

* [Servos](https://www.adafruit.com/product/1967)
* [Webcam]()
* Arduino Uno

## Installation

* Clone or download this repository [https://github.com/montoyamoraga/servo_camera](https://github.com/montoyamoraga/servo_camera)

* Make sure you are using Python 2.x.

```shell
python --version
```

* Install the virtualenv python module

```shell
pip install virtualenv
```

* Upload the script arduino_servo_camera.ino to the Arduino Uno.

* Connect the servo motors to the Arduino.

![00_connections](https://github.com/montoyamoraga/servo_camera/blob/master/pics/00_connections.jpg "servo_camera")

![01_servos](https://github.com/montoyamoraga/servo_camera/blob/master/pics/01_servos.jpg "servo_camera")

## Usage

* Open terminal and go to the directory

```shell
cd Desktop/servo_camera
```

* Initialize a virtual environment, call it env

```shell
python virtualenv env
```

* Activate the virtual environment

```shell
source env/bin/activate
```

* Install pyserial

```shell
pip install pyserial
```

* Open the Python script servo_camera.py

* Update the arduinoPort variable if needed

```python
arduinoPort = '/dev/cu.usbmodem1461'
```
* Run the Python script on terminal

```shell
python servo_camera.py
```

This script is making the camera infinitely loop through the sequence [0,0], [90, 90], [180, 180], [90, 90].

* When finished, deactivate the virtual environment

```shell
deactivate
```

## Bibliography

* [Arduino and Python](https://playground.arduino.cc/Interfacing/Python)
* [pyserial](https://github.com/pyserial/pyserial)
