#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;
#define MQ2pin (0)  // define the analog pin of the gas sensor

float sensorValue;  //variable to store sensor value

void setup() {
  Serial.begin(9600);
 Serial.println("Gas sensor warming up!");  // allow the gas sensor to warm up
delay(1000); //gives a delay for the gas sensor to warm up
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);  // prinst the gas sensor value
  
  if(sensorValue < 400)
  {
    Serial.print(" | Smoke detected!");
  }
  else{
  Serial.println(" No smoke detected");}
  delay(1000); // wait 2s for next reading
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println("*C");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println("hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println("m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println("%");

  Serial.println();
  delay(1000);
}
