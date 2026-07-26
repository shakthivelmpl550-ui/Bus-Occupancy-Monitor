# Bus-Occupancy-Monitor
The Smart Bus Student Monitoring System is an IoT-based project that uses ESP32 and an ultrasonic sensor to monitor student occupancy in real time. 
The system displays the student count on an LCD and provides LED and buzzer alerts during overcapacity conditions, improving bus safety and management.

## Hardware Components

- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor (Student detection)
- 16x2 LCD Display
- Potentiometer (LCD contrast adjustment)
- Push Button (Stop/Manual control)
- LED Indicator
- Buzzer Alert
- Jumper Wires


## Working Principle

The HC-SR04 ultrasonic sensor detects students entering the bus and calculates the number of students. The ESP32 processes the sensor data and displays the student count and status on the 16x2 LCD display.

The potentiometer is used to adjust the LCD contrast for better visibility. The push button is used for manual stop/data recording, while the LED and buzzer provide alerts during high occupancy conditions.

The system helps in real-time bus student monitoring and improves safety by preventing overloading.

