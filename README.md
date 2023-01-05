# Welcome to our project : Detection-alarm 🔐

<p align="center">
  <img src="Images/Logo2.png" width="100">
</p>

## 💡 Introduction

Detection alarm is a 3rd year engineering school project at Polytech Grenoble in the IESE speciality. This project is part of the IoT courses we follow with 16h of practical work in order to carry out this project.

## ⚙️ Features

- Detection with an angle of 120 degrees and up to a distance of 6 meters
- Warning with light effects
- Wall mounting check
- Bluetooth Low Energy (BLE) communication
- Cheap
- Controllable with an Android application :
  - Enable/disable alarm
  - See how many people have been detected
  - View detection history
  

## 📲 Quick start guide and documentation

For more informations, please take a look at the [report](https://github.com/AlexFouilleul/Detection-alarm/blob/main/Report/report.md) available (FR).


## 💻 Compatible equipments

### Hardware
- [Arduino Tiny Machine Learning Kit](https://store.arduino.cc/products/arduino-tiny-machine-learning-kit) based on Arduino Nano 33 BLE
- [Grove buzzer](https://wiki.seeedstudio.com/Grove-Buzzer/)
- [Grove PIR sensor](https://wiki.seeedstudio.com/Grove-PIR_Motion_Sensor/)
- [Grove button](https://wiki.seeedstudio.com/Grove-Button/)
- Ligthstrip (8*LED WS2812B) 

### Software
- "[LightBlue® - Bluetooth Low Energy](https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer&hl=fr&gl=US&pli=1)" available on the Google Play Store and Apple App Store<br>
or
- "[Detection alarm](https://github.com/AlexFouilleul/Detection-alarm/blob/main/Application/Detection_alarm.apk)" application available in this repository

### Others
- Power alimentation with phone charger and micro USB cable
- Plywood with 3mm thickness for the case

## 🛠️ Issues
- Due to security restrictions put in place by Google on Android, the application does not work on Android 13.
- The Arduino can only deliver low power so the brightness of the LEDs is limited.
- The Android application created only allows sending data from the Arduino to the smartphone. The reverse is not possible because of the format of the data exchanged between the two devices.

## 🧑‍💻 Contributors

Anas Bachri (dev) - [anas.bachri@etu.univ-grenoble-alpes.fr](mailto:Anas.Bachri@etu.univ-grenoble-alpes.fr)<br>
Alex Fouilleul (dev) - [alex.fouilleul@etu.univ-grenoble-alpes.fr](mailto:alex.fouilleul@etu.univ-grenoble-alpes.fr)<br>

Polytech Grenoble - IESE5<br>
IoT project, 2022 - 2023

<p align="left">
  <img src="Images/Logo_polytech.png" width="200">
</p>
