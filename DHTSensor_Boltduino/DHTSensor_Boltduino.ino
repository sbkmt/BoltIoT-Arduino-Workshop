// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - Bolt IoT Library: https://github.com/Inventrom/boltiot-arduino-helper

#include <boltiot.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Enter Your Bolt Device Credentials
#define API_KEY     "xxxxxx-xxxx-xxxx-xxxx-xxxxxx"
#define DEVICE_ID   "BOLTxxxxxxxx"
#define DHTPIN 2   // Defining DHT Senor Pin that is connected with Boltduino

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  boltiot.begin(Serial);  //Initialize the Bolt interface over serial UART
  pinMode(2,INPUT);  //Set pin 2 as the input
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements:
  delay(500);

  // Read the humidity in %:
  float humidity = dht.readHumidity();
  // Read the temperature as Celsius:
  float temperature = dht.readTemperature();

  // Pushing values on Bolt Cloud
  boltiot.processPushDataCommand(temperature, humidity);
}
