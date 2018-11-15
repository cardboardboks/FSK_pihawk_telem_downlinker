// Simple I2C test for ebay 128x64 oled1.

#include <Wire.h>
#include "src\SSD1306Ascii\src\SSD1306Ascii.h"
#include "src\SSD1306Ascii\src\SSD1306AsciiWire.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS1 0x3C
#define I2C_ADDRESS2 0x3D

SSD1306AsciiWire oled1;
SSD1306AsciiWire oled2;
//------------------------------------------------------------------------------
void setup() {
  Wire.begin();
  Wire.setClock(400000L);

  oled1.begin(&Adafruit128x64, I2C_ADDRESS1);
  oled2.begin(&Adafruit128x64, I2C_ADDRESS2);

  oled1.setFont(X11fixed7x14);
  oled2.setFont(X11fixed7x14);

  oled1.clear();
  oled2.clear();

}
//------------------------------------------------------------------------------
void loop() {

  delay(5000);
  oled1.clear();

  oled1.setCursor(0, 0);
  oled1.print("Crs:239");
  oled1.setCursor(0, 2);
  oled1.print("ALT:314M");
  oled1.setCursor(0, 4);
  oled1.print("Lat:-37.80213");
  oled1.setCursor(0, 6);
  oled1.print("Lon:174.83123");

  oled1.setCursor(58, 0);
  oled1.print("Spd:152kph");
  oled1.setCursor(65, 2);
  oled1.print("Dst:1.4Km");
  oled1.setCursor(100, 4);
  oled1.print("FBWA");
  oled1.setCursor(100, 6);
  oled1.print("Darm");

  delay(5000);
  oled1.clear();

  oled1.setCursor(0, 0);
  oled1.print("Vlt:23.4v");
  oled1.setCursor(0, 2);
  oled1.print("Bat:100%");
  oled1.setCursor(0, 4);
  oled1.print("Lnk:100%");
  oled1.setCursor(0, 6);
  oled1.print("Log:12406");

  oled1.setCursor(70, 0);
  oled1.print("Cur:314A");
  oled1.setCursor(70, 2);
  oled1.print("Sat:85");
  oled1.setCursor(70, 4);
  oled1.print("HRT: O");
  oled1.setCursor(70, 6);
  oled1.print("856985");
}
