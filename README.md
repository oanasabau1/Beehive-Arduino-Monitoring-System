# Beehive Arduino Monitoring System

## About

A simple Arduino-based project for monitoring beehive conditions and activity. It uses a DHT11 sensor to measure temperature and humidity, and an IR sensor to count passing bees. Real-time data is displayed on an LCD and the Serial Monitor, making it an ideal tool for beekeepers to track hive health and activity.

## Key Components

### 1. **DHT11 Sensor**
- **Purpose:** Measures temperature and humidity inside the beehive.
- **Functionality:**
  - Reads and validates temperature and humidity values.
  - Displays data on an LCD screen and logs to the Serial Monitor.

### 2. **IR (Infrared) Sensor**
- **Purpose:** Detects bee activity by measuring changes in the IR signal.
- **Functionality:**
  - When the IR signal drops below a threshold (indicating obstruction), it assumes a bee has passed.
  - Increments the bee count and logs the detection to the Serial Monitor.

### 3. **Liquid Crystal Display (LCD)**
- **Purpose:** Provides a real-time visual interface.
- **Functionality:**
  - Displays current temperature, humidity, and total bee count.

## Step-by-Step Functionality

### **1. Initialization (Setup Phase)**
- Configures Serial Monitor for logging outputs.
- Initializes the LCD screen and displays a startup message.
- Prepares the DHT sensor for temperature and humidity measurements.

### **2. Continuous Monitoring (Loop Phase)**
- **Every second, the system performs the following steps:**
  1. **Read Temperature and Humidity:**
     - Collects data from the DHT11 sensor.
     - Validates the readings and alerts the user if there is an error.
     - Logs the data to the Serial Monitor and displays it on the LCD.
  2. **Monitor Bee Activity:**
     - Reads the IR sensor’s analog value.
     - Detects bee activity based on a configurable threshold.
     - Logs whether a bee was detected and updates the total bee count.
  3. **Update the LCD Screen:**
     - Displays real-time temperature, humidity, and bee count information.
     
## User Feedback
- **LCD Screen:** Provides a visual display of hive conditions and bee count.
- **Serial Monitor:** Logs detailed readings and events, including:
  - Temperature and humidity measurements.
  - IR sensor values.
  - Bee detection status and total count.

## Features
- **Accuracy and Validation:** Ensures reliable temperature and humidity readings by checking sensor data for validity.
- **Real-Time Display:** Offers continuous updates on both the LCD screen and Serial Monitor.
- **Bee Counting Logic:** Tracks bee activity using an IR sensor with adjustable sensitivity to suit various setups.


## Use Case
This system is ideal for beekeepers looking to:
- Monitor temperature and humidity conditions within their hive.
- Track the activity of bees entering or exiting the hive.
- Access hive information on an integrated screen or a computer connected to the system.

## Hardware Requirements:

   - Arduino Uno R3 board
   - DHT11 temperature and humidity sensor
   - 10 kΩ Resistor
   - IR sensor (HW 870)
   - LCD screen (I2C-compatible)
   - Connecting wires
   - Breadboard


