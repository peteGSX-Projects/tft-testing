#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#define TEXT_SIZE 1
#define ROTATION 1
#define TEXT_FONT &FreeMono9pt7b
#define TEXT_COLOUR TFT_WHITE
#define BACKGROUND_COLOUR TFT_BLACK

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  Serial.println(F("Touch Testing"));
  tft.begin();
  tft.fillScreen(BACKGROUND_COLOUR);
}

void loop() {
  uint16_t touchX, touchY;
  if (tft.getTouch(&touchX, &touchY)) {
    Serial.print(F("Touched X|Y: "));
    Serial.print(touchX);
    Serial.print(F("|"));
    Serial.println(touchY);
  }

}


