# Fume Sensor with ATmega328P (Internal 8MHz Clock)

## Overview
This project utilizes the **Sharp GP2Y1014AU0F** dust sensor to detect soldering fumes and activates a ventilator to disperse them, ensuring a safer workspace. The setup is powered by an **ATmega328P** microcontroller running on its internal 8MHz clock.

## Components
- **Microcontroller**: ATmega328P
- **Dust Sensor**: Sharp GP2Y1014AU0F
- **Ventilator**: Activated when fumes are detected. I used a small ventilator, so i just send a logic 1 to activate it, you might need a relay and separate power supply.
- **Power Supply**: 5V (adjust as necessary for your setup)

## How It Works
The **Sharp GP2Y1014AU0F** sensor measures air quality, specifically the presence of particulate matter in the air. The ATmega328P processes these readings and, if the fumes exceed a certain threshold, activates a ventilator to disperse them.

## Features
- **Efficient Fume Detection**: Real-time monitoring of soldering fumes.
- **Automatic Ventilation**: Activates ventilator upon detecting fumes above threshold.
- **Standalone Operation**: Powered by ATmega328P’s internal 8MHz clock, eliminating the need for an external crystal.

## Getting Started
1. **Setup**: Connect the GP2Y1014AU0F sensor and ventilator to the ATmega328P as per the wiring diagram.
2. **Upload the Code**: Upload the Arduino sketch to the ATmega328P with internal clock, with the help of [Minicore](https://github.com/MCUdude/MiniCore/)
3. **Calibration**: Adjust the fume threshold in the code, if necessary, for your workspace.
