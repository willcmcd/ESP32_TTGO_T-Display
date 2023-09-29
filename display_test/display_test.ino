// Simple test of device display functionality.

#include <TFT_eSPI.h>
// to get display to work when using LilyGo TTGO T-Display, find and uncomment the following line
// in the TFT_eSPI User_Setup_Select.h file. [Documents/arduino/libraries/TFT_eSPI/]
// #include <User_Setups/Setup26_TTGO_T_Display.h>

#define DISP_W 135
#define DISP_H 240

TFT_eSPI tft = TFT_eSPI(DISP_W, DISP_H);

uint8_t counter = 0;

void init_tft() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_LIGHTGREY);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Serial Init.");

  init_tft();
  Serial.println("TFT Init.");

  // create header
  tft.setTextSize(3);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setCursor(10, 10);
  tft.println("DISPLAY TEST");

  // configure counter text
  tft.setTextSize(5);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);

  delay(1000);
  Serial.println("Setup func complete.");
}

void loop() {
  tft.setCursor(80, 50);
  tft.printf("%03u", counter++);

  delay(100);
}
