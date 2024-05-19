#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SH110X.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeMono18pt7b.h>
#include <Fonts/FreeMono24pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans24pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define TEXT_SIZE 1
#define ROTATION 0
#define TEXT_FONT &FreeMono9pt7b
#define OLED_ADDRESS 0x3C

#define SCREEN_TYPE OLED_SSD1306

#if SCREEN_TYPE == OLED_SSD1306
Adafruit_SSD1306 oled = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
#elif SCREEN_TYPE == OLED_SH1106
Adafruit_SH1106G oled = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
#endif

uint8_t fontHeight = 0;
uint8_t fontWidth = 0;
uint8_t maxRows = 0;
uint8_t maxColumns = 0;

unsigned long lastDisplay = 0;
unsigned long displayDelay = 1000;

void setup() {
  Serial.begin(115200);
  Serial.println(F("OLED Testing"));
  const GFXfont *gfxFont = TEXT_FONT;
#if SCREEN_TYPE == OLED_SSD1306
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
#elif SCREEN_TYPE == OLED_SH1106
  oled.begin(OLED_ADDRESS);
#endif
  oled.setRotation(ROTATION);
  oled.setFont(gfxFont);
  oled.setTextSize(TEXT_SIZE);
  oled.display();
  delay(2000);
  oled.clearDisplay();
  oled.display();
  fontHeight = gfxFont->yAdvance;
  fontWidth = getTextWidth();
  maxRows = oled.height() / fontHeight;
  maxColumns = oled.width() / fontWidth;
  Serial.print(F("Setup done: fontHeight|fontWidth|tftHeight|tftWidth|maxRows|maxColumns: "));
  Serial.print(fontHeight);
  Serial.print(F("|"));
  Serial.print(fontWidth);
  Serial.print(F("|"));
  Serial.print(oled.height());
  Serial.print(F("|"));
  Serial.print(oled.width());
  Serial.print(F("|"));
  Serial.print(maxRows);
  Serial.print(F("|"));
  Serial.println(maxColumns);
  oled.setCursor(0, fontHeight);
  oled.setTextColor(WHITE);
  oled.print("Testing");
  oled.display();
}

void loop() {
  if (millis() - lastDisplay > displayDelay) {
    lastDisplay = millis();
    oled.clearDisplay();
    oled.display();
    for (uint8_t i = 0; i < maxRows; i++) {
      int16_t y = (i * fontHeight) + fontHeight;
      oled.setCursor(0, y);
      oled.print("Test row ");
      oled.print(i);
    }
    oled.display();
  }
}

uint8_t getTextWidth() {
  int16_t x1, y1;
  uint16_t w, h;
  oled.getTextBounds("A", 0, 0, &x1, &y1, &w, &h);
  return w;
}
