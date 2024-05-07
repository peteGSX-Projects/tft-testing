#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <Fonts/FreeMono12pt7b.h>

MCUFRIEND_kbv tft;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Testing"));
  uint16_t screenId = tft.readID();
  tft.begin(screenId);
  tft.setTextSize(1);
  tft.setRotation(1);
  const GFXfont *gfxFont = &FreeMono12pt7b;
  tft.setFont(gfxFont);
  uint8_t fontHeight = gfxFont->yAdvance;
  Serial.print(F("Font height: "));
  Serial.println(fontHeight);
}

void loop() {

}
