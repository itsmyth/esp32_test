#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define RGB_LED_PIN 38
#define NUM_PIXELS 1

Adafruit_NeoPixel pixel(NUM_PIXELS, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  delay(1000);

  pixel.begin();
  pixel.setBrightness(50);

  // Get PSRAM size
  size_t psramSize = ESP.getPsramSize();
  Serial.print("PSRAM Size: ");
  Serial.print(psramSize);
  Serial.println(" bytes");

  // Flash size can be checked via ESP.getFlashChipSize()
  uint32_t flashSize = ESP.getFlashChipSize();
  Serial.print("Flash Size: ");
  Serial.print(flashSize);
  Serial.println(" bytes");
}

void loop() {
  pixel.setPixelColor(0, pixel.Color(0, 0, 255));
  pixel.show();
  delay(500);
  pixel.setPixelColor(0, pixel.Color(0, 0, 0));
  pixel.show();
  delay(500);

}
