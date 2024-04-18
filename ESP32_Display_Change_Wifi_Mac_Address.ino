//ESP32 display and then change the Wifi Mac Address
//Video walkthrough: https://youtu.be/EW8Ft5zJi68

#include <WiFi.h>
#include "esp_wifi.h"

//Add your wifi network's credentials here
const char* ssid     = "";
const char* password = "";

void setup()
{
    Serial.begin(115200);
    delay(1000);

    WiFi.mode(WIFI_STA);

    //Display the ESP32's default Mac Address
    Serial.print("This ESP32's default Mac Address is:  ");
    Serial.println(WiFi.macAddress());

    //Temporarily change the ESP32's Mac Address
    //Note that this will only override the ESP32's Mac address while this sketch is running.
    //If you upload a new sketch then the ESP32 will revert to its factory set Mac Address.
    //Note: The bit 0 of the first byte of MAC address cannot be 1 (so it can be 0xA0 but not 0xA1).
    uint8_t newMacAddress[] = {0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};
    
    //To decrypt the result look in here: https://github.com/espressif/esp-idf/blob/v5.2.1/components/esp_wifi/include/esp_wifi.h
    //The base error is 0x3000 (12288 in decimal) so ESP_ERR_WIFI_NOT_INIT is 12289
    //An error of 0 means the Mac Address change was successful
    esp_err_t macAddressChangeResult = esp_wifi_set_mac(WIFI_IF_STA, &newMacAddress[0]);

    if (macAddressChangeResult == ESP_OK) {
      Serial.println("Mac Address successfully changed!");
      Serial.print("This ESP32's new Mac Address is:  ");
      Serial.println(WiFi.macAddress());
      Serial.println("");

      //Connect to wifi using the new Mac Address
      connectToWifi();
    } else {
      Serial.print("Mac change not changed. Check this value of esp_err_t: ");
      Serial.println(macAddressChangeResult);
    }

}

void connectToWifi() {
  Serial.print("Connecting to wifi network ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to wifi network ");
  Serial.print(ssid);
  Serial.println("!");
  Serial.print("ESP32's local IP address: ");
  Serial.println(WiFi.localIP());
}

void loop(){} //Loop not required for this sketch but it won't compile without this function