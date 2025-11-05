#include <WiFi.h>
#include <ESPmDNS.h>

const char* ssid = "YourWiFi";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  if (!MDNS.begin("esp32")) {  // Set mDNS hostname
    Serial.println("Error starting mDNS");
    return;
  }
  
  Serial.println("mDNS responder started. Access at http://esp32.local");
}

void loop() {
  MDNS.update();
}
