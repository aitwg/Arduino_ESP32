#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define ESP32_SCL 22
#define ESP32_SDA 21
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ESP32_SCL, /* data=*/ESP32_SDA, /* reset=*/ U8X8_PIN_NONE);  //ESP8266板子搭配SSD1306用這行
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //Arduino搭配SSD1306(0.96" OLED)用這行
//U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //Arduino搭配SH1106(1.3" OLED)用這行

#define imgWidth 128
#define imgHeight 48  //這裡只用到48的高度，因為上方要放文字

static const unsigned char PROGMEM android[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfc, 0x3f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xff, 0xff, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfe, 0x7f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfe, 0x7f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xe0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x07, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xe0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x07, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xe0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x07, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xe0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x07, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xc0, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x03, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x80, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x01, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1f, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};

static const unsigned char PROGMEM android_2[]  = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x03, 0xc0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x00, 0x00, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x01, 0x80, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfe, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x1f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf8, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x1f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf8, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf0, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x1f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xf8, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x3f, 0x38, 0x00, 0x00, 0x00, 0x00, 0x1c, 0xfc, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x7f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xfe, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xe0, 0x07, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf0, 0x0f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf8, 0x1f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,};

static const unsigned char PROGMEM android_apple[]  = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x40, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xf9, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x80, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x00, 
0x00, 0x00, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xe0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x7f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xf8, 0xfc, 0x7f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x78, 0xfc, 0x3f, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x7c, 0xfc, 0x3f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xfe, 0xfe, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc0, 0x00, 0x06, 0x00, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x80, 0xff, 0x01, 0xc0, 0x7f, 0x00, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x0f, 0xf8, 0xff, 0x01, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 
0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 
0x00, 0x1e, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 
0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 
0x00, 0x00, 0xf8, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x03, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x3f, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0xff, 0x0f, 0xfc, 0x3f, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1f, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x03, 0xe0, 0x1f, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x80, 0x07, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup(void) {
  u8g2.begin();    
}

void loop(void) {
  u8g2.setFont(u8g2_font_HelvetiPixelOutline_te); //設定字型
  u8g2.firstPage();
  do {
    u8g2.drawStr(0,13,"Hello Arduino");  //輸出文字
    u8g2.drawXBMP(0,16, imgWidth, imgHeight, android);  //繪圖
  } while ( u8g2.nextPage() );
  delay(5000);
  u8g2.firstPage();
  do {
    u8g2.drawStr(0,13,"Hello Arduino");  //輸出文字
    u8g2.drawXBMP(0,16, imgWidth, imgHeight, android_2);  //繪圖
  } while ( u8g2.nextPage() );
  delay(5000);
  u8g2.firstPage();
  do {
    //u8g2.drawStr(0,13,"Hello Arduino");  //輸出文字
    u8g2.drawXBMP(0,0, imgWidth, imgHeight+16, android_apple);  //繪圖
  } while ( u8g2.nextPage() );
  delay(5000);
}
