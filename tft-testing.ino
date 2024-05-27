#include <Arduino.h>
#include <SPI.h>
// #include "ClearSetup.h"
#define USER_SETUP_LOADED
#include "myUserSetup.h"
#include <TFT_eSPI.h>

#define TEXT_SIZE 1
#define ROTATION 1
#define TEXT_FONT &FreeMono9pt7b
#define TEXT_COLOUR TFT_WHITE
#define BACKGROUND_COLOUR TFT_BLACK

// #include "ClearSetup.h"

TFT_eSPI tft1 = TFT_eSPI();
// #include "ClearSetup.h"
// TFT_eSPI tft2 = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  Serial.println(F("Multi TFT Testing"));
  tft1.begin();
  tft1.setTextColor(TEXT_COLOUR);
  tft1.setFreeFont(TEXT_FONT);
  tft1.setRotation(ROTATION);
  tft1.setTextSize(TEXT_SIZE);
  tft1.fillScreen(BACKGROUND_COLOUR);
  tft1.setCursor(0, 40);
  tft1.print(F("Multi TFT testing"));
}

void loop() {
// #ifdef TOUCH_CS
//   uint16_t touchX, touchY;
//   if (tft1.getTouch(&touchX, &touchY)) {
//     Serial.print(F("Touch X|Y: "));
//     Serial.print(touchX);
//     Serial.print(F("|"));
//     Serial.println(touchY);
//   }
// #endif
}
