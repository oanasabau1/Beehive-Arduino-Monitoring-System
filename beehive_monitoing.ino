/*
This code monitors beehive conditions and activity, ensuring accurate readings of temperature and humidity
using a DHT sensor with error validation. It displays data in real time on an LCD and via
the Serial Monitor. Bee activity is tracked using an IR sensor that detects passing bees based on
infrared light changes, with adjustable sensitivity. 
Ideal for beekeepers, it provides an easy way to monitor hive conditions
and bee movements on both a screen and a computer.
*/

#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// Pin definitions for DHT sensor and IR sensor
#define DHTPIN 4         // Pin for DHT11 sensor data
#define DHTTYPE DHT11    // Define the type of DHT sensor
const int pinIRa = A0;    // Analog pin for the IR sensor's analog output

// Initialize the LCD and DHT sensor
LiquidCrystal_I2C lcd(0x27, 16, 2);  
DHT dht(DHTPIN, DHTTYPE);

// Variables to store IR sensor readings and bee count
int IRvalueA = 0;                    
int objectCount = 0;                 // Counter for detected bees

void setup() {

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(pinIRa, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Beehive Check!");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();

  Serial.println("-----------------------------------------");
  Serial.println("   Beehive Monitoring System Initialized");
  Serial.println("-----------------------------------------");
}

void loop() {
  // Read temperature and humidity from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Validate sensor readings
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Failed to read from DHT sensor!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Read Error");
    delay(2000);
    return;
  }

  // Print temperature and humidity to Serial Monitor
  Serial.println("-----------------------------------------");
  Serial.println("Temperature and Humidity Readings:");
  Serial.println("-----------------------------------------");
  Serial.print("Temperature (C): ");
  Serial.println(temperature, 2);
  Serial.print("Humidity (%): ");
  Serial.println(humidity, 2);

  // Read the analog value from the IR sensor
  IRvalueA = analogRead(pinIRa);

  // Print IR sensor readings to Serial Monitor
  Serial.println("-----------------------------------------");
  Serial.println("IR Sensor Status:");
  Serial.println("-----------------------------------------");
  Serial.print("IR Sensor Value: ");
  Serial.println(IRvalueA);

  // Check if a bee is detected based on the IR sensor value
  if (IRvalueA < 500) {  
    objectCount++;  
    Serial.println("Status: Bee Detected!");
  } else {
    Serial.println("Status: No Bee Detected!");
  }

  // Print the total bee count to Serial Monitor
  Serial.print("Total Bee Count: ");
  Serial.println(objectCount);
  Serial.println("-----------------------------------------");
  Serial.println(); 

  // Display temperature, humidity, and bee count on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);  
  lcd.print("C, H:");
  lcd.print(humidity, 1);    
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Bees counted: ");
  lcd.print(objectCount);

  delay(1000);
}
