# servo_camera

## About

This project by [Aarón Montoya-Moraga](http://montoyamoraga.io/) consists of a webcam on a servo that can be controlled from a Python script.

Developed for [Sam Lavigne](http://lav.io/)'s [Automating video](https://github.com/antiboredom/automating-video-itp) class, at [New York University](http://www.nyu.edu/)'s [Interactive Telecommunications Program](https://tisch.nyu.edu/itp), November 2017.

## Environment

This project was programmed and tested using the following software and hardware:

* Macbook running macOS High Sierra
* Arduino IDE 1.8.3
* Python 2.7.10
* Python module [virtualenv](https://virtualenv.pypa.io/en/stable/) 15.1.0
*

## Code

* Arduino script to receive commands from the Python script.
* Python script.

## Materials

* [Servos](https://www.adafruit.com/product/1967)
* [Webcam]()
*

## Usage

* Clone or download this repository

* Open terminal and go to the directory

```shell
cd blabla/servo_camera
```

* Check that you are using Python 2.x

```shell
python --version
```

* Check that you have virtualenv

```shell
virtualenv --version
```

Or install it

```shell
pip install virtualenv
```

* Initialize a virtual environment, call it env

```shell
python virtualenv env
```

* Activate the virtual environment

```shell
source env/bin/activate
```

* Deactivate the virtual environment

```shell
source env/bin/activate
```

## Bibliography

* [Arduino and Python](https://playground.arduino.cc/Interfacing/Python)
* [pyserial](https://github.com/pyserial/pyserial)
