# Arduino Uno R3 Multifunctional Shield
This repository contains the design files and code for a highly compact and versatile shield designed for the Arduino Uno R3 board. With dimensions of less than 6cm x 6cm, this shield offers an array of functions including LEDs, push button detection, distance measurement, RGB LED control, orientation sensing, light level measurement, temperature and humidity detection, infrared signal reception, analog input, and a joystick function. It transforms your Uno R3 into a powerful and adaptable tool for a wide range of electronics projects.

## Key Features
The Multifunctional Shield extends the capabilities of your Arduino Uno R3 with the following features:
1. **LEDs**: Two onboard LEDs for visual feedback and status indication.
2. **RGB LED**: Allows control of colors and lighting effects, enhancing visual feedback and creative possibilities.
3. **Potentiometer**: Includes a potentiometer for analog input, ideal for adjusting parameters or settings.
4. **Push Button**: Detects button presses, making it suitable for user input.
5. **Active Buzzer**: An active buzzer is also integrated into the shield for audio feedback and alerting.
6. **Ultrasonic Sensor**: Measures distance using an ultrasonic sensor, enabling applications such as obstacle detection.
7. **Temperature and Humidity Sensor (DHT11)**: Provides accurate temperature and humidity readings for environmental monitoring.
8. **Infrared (IR) Receiver**: Capable of receiving IR signals, opening up possibilities for remote control applications.
9. **Joystick Function**: The shield also includes a joystick function, expanding the range of input options for your projects.
10. **Tilt Ball Sensor**: Detects orientation changes or tilting movements.
11. **Photoresistor**: Measures ambient light levels, useful for light-sensitive applications.

## Contents
1. **Sch&Pcb.zip**: This archive contains the schematic and PCB design files for the Multifunctional Shield. These files are essential for understanding and customizing the hardware components of the shield.

<img width="1010" alt="Screen Shot 2023-09-09 at 4 41 20 PM" src="https://github.com/chenw7/UnoR3_Multifunctional_Shield/assets/91576538/326395fc-5f83-4be5-aead-4422d3f17206">

<img width="794" alt="Screen Shot 2023-09-09 at 4 41 48 PM" src="https://github.com/chenw7/UnoR3_Multifunctional_Shield/assets/91576538/4035fbdc-9518-4acd-b2f1-7cd0a70b94ec">

2. **Multifunc.ino**: The "Multifunc.ino" file contains the Arduino code for the Multifunctional Shield. It includes pre-written functions and pin configurations that simplify the use of the shield's features. Users can easily incorporate these functions into their own projects.
3. **Dht11.zip**: This ZIP library should be imported into the "Multifunc.ino" file. It provides support for the DHT11 sensor, allowing the shield to accurately detect temperature and humidity.
4. **Manufacturing.zip**: The "Manufacturing.zip" archive contains Gerber and drill files necessary for PCB manufacturing. These files are intended to be sent to manufacturing companies for the production of the Multifunctional Shield's PCB.

## Getting Started
To start using the Multifunctional Shield and its features, follow these steps:
1. **Hardware Setup**: Refer to the schematic and PCB design files in "Sch&Pcb.zip" for guidance on assembling the shield.
2. **DHT11 Library**: Include the "Dht11.zip" library in your Arduino IDE to enable support for the DHT11 sensor. To do this, follow these steps in the Arduino IDE:
   Go to Sketch -> Include Library -> Add .zip Library.
   Select the "Dht11.zip" library file and import it into your project.
3. **IR Remote Library**: In the Arduino IDE, go to Tools -> Manage Libraries, search for IRremote, and install it. This step is essential for using the IR receiver functionality in "Multifunc.ino."
4. **Code Usage**: Utilize the functions and pin configurations provided in "Multifunc.ino" to access and control the shield's features in your projects. All functions for components such as LEDs, buzzers, sensors, and the joystick function have been pre-written for your convenience.

## Finished Product
Preview of the PCB produced by 3D viewer in Kicad

<img width="456" alt="Screen Shot 2023-09-09 at 4 25 26 PM" src="https://github.com/chenw7/UnoR3_Multifunctional_Shield/assets/91576538/9e75ebaa-3995-4e87-aaf6-7591b2aeee5c">

Actual PCB

<img width="641" alt="Screen Shot 2023-09-09 at 4 29 33 PM" src="https://github.com/chenw7/UnoR3_Multifunctional_Shield/assets/91576538/5745440e-b489-4537-86b0-f834795d7b30">

PCB with Components Installed

<img width="720" alt="Screen Shot 2023-09-09 at 4 36 10 PM" src="https://github.com/chenw7/UnoR3_Multifunctional_Shield/assets/91576538/2c4b26f6-3e04-466e-a1b4-5921c2c731ea">
