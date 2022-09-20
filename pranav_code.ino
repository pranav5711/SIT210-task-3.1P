#include "thingProperties.h"
#include <DHT.h>;
#include<Adafruit_Sensor.h>
#define DHTPIN 2     
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  dht.begin();
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
 
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  temp = dht.readTemperature();
  Serial.print(" %, Temperature: ");
  Serial.print(temp);
  Serial.println("Celsius");
  delay(1000);
}

void onLedChange()  {
  digitalWrite(13, led);
  delay(3000);
}
