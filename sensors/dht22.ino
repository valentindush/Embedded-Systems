#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2
// Set DHT type, uncomment whatever type you're using!
// #define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 

}

void loop() {

  // Wait a few seconds between measurements:
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Read the humidity in %:
  float h = dht.readHumidity();
  // Read the temperature as Celsius:
  float t = dht.readTemperature();
  // Read the temperature as Fahrenheit:
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again):
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (default):
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius:
  float hic = dht.computeHeatIndex(t, h, false);


  lcd.clear();
  lcd.setCursor(2,0);   
  lcd.print("H: ");
  lcd.print(h);
  lcd.print("%  ");

  lcd.setCursor(2,1);   


  lcd.print("T: ");
  lcd.print(t);
  lcd.print("C  ");


  // Serial.print("Humidity: ");
  // Serial.print(h);
  // Serial.print(" % ");
  // Serial.print("Temperature: ");
  // Serial.print(t);
  // Serial.print(" \xC2\xB0");
  // Serial.print("C | ");
  // Serial.print(f);
  // Serial.print(" \xC2\xB0");
  // Serial.print("F ");
  // Serial.print("Heat index: ");
  // Serial.print(hic);
  // Serial.print(" \xC2\xB0");
  // Serial.print("C | ");
  // Serial.print(hif);
  // Serial.print(" \xC2\xB0");
  // Serial.println("F");

  
}