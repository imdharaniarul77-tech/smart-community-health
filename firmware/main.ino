// ESP32 Arduino code for WiFi and sensor integration
#include <WiFi.h>
#include <DHT.h>

#define DHTPIN 4         // DHT sensor pin
#define DHTTYPE DHT11    // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "your-SSID";   // Replace with your network SSID
const char* password = "your-PASSWORD"; // Replace with your network password

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %	");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
}