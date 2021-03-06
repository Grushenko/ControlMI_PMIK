#ifndef OLED_SSD1306_H
#define OLED_SSD1306_H

#define SSD1306_FONTS

/*!
 * @file
 * File is SDD1306 driver.
 * Responsible for all commands being sent to the display.
 */

#include <stdint.h>
#include "stm32f3xx_hal.h"

#define SSD1306_DEFAULT_ADDRESS     0x78
#define SSD1306_SETCONTRAST         0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON        0xA5
#define SSD1306_NORMALDISPLAY       0xA6
#define SSD1306_INVERTDISPLAY       0xA7
#define SSD1306_DISPLAYOFF          0xAE
#define SSD1306_DISPLAYON           0xAF
#define SSD1306_SETDISPLAYOFFSET    0xD3
#define SSD1306_SETCOMPINS          0xDA
#define SSD1306_SETVCOMDETECT       0xDB
#define SSD1306_SETDISPLAYCLOCKDIV  0xD5
#define SSD1306_SETPRECHARGE        0xD9
#define SSD1306_SETMULTIPLEX        0xA8
#define SSD1306_SETLOWCOLUMN        0x00
#define SSD1306_SETHIGHCOLUMN       0x10
#define SSD1306_SETSTARTLINE        0x40
#define SSD1306_MEMORYMODE          0x20
#define SSD1306_COLUMNADDR          0x21
#define SSD1306_PAGEADDR            0x22
#define SSD1306_COMSCANINC          0xC0
#define SSD1306_COMSCANDEC          0xC8
#define SSD1306_SEGREMAP            0xA0
#define SSD1306_CHARGEPUMP          0x8D
#define SSD1306_SWITCHCAPVCC        0x02
#define SSD1306_NOP                 0xE3

typedef struct {
    I2C_HandleTypeDef* I2C;
    uint8_t address;
} SSD1306_Dev;

/**
 * Inits display of given structure
 * @param pDisplay
 */
void SSD1306_init(SSD1306_Dev* pDisplay);
/**
 * Enables display
 * @param pDisplay display handler
 * @param pEnable do enable?
 */
void SSD1306_enable(SSD1306_Dev* pDisplay, uint8_t pEnable);
/**
 * Invert displayed image
 * @param pDisplay display handler
 * @param pInvert do invert?
 */
void SSD1306_invert(SSD1306_Dev* pDisplay, uint8_t pInvert);
/**
 * Send full frame buffer to display
 * @param pDisplay display handler
 * @param pBuffer frame buffer
 */
void SSD1306_sendFrameBuffer(SSD1306_Dev* pDisplay, uint8_t* pBuffer);

/**
 * Send command to display
 * @param pDisplay display handler
 * @param pCommand command code
 */
void SSD1306_sendCommand(SSD1306_Dev* pDisplay, uint8_t pCommand);

/**
 * Clera screen
 * @param pDisplay display handler
 */
void SSD1306_clear(SSD1306_Dev* pDisplay);
/**
 * Draw glyph on display
 * @param pDisplay display handler
 * @param pX x coord
 * @param pY y coord
 * @param pGlyph glyph array
 */
void SSD1306_drawGlyph(SSD1306_Dev* pDisplay, uint8_t pX, uint8_t pY, uint8_t* pGlyph);
/**
 * Draw character on display
 * @param pDisplay display handler
 * @param pX x coord
 * @param pY y coord
 * @param pChar character
 */
void SSD1306_drawChar(SSD1306_Dev* pDisplay, uint8_t pX, uint8_t pY, char pChar);
/**
 * Draw string on display
 * @param pDisplay display handler
 * @param pX x coord
 * @param pY y coord
 * @param pString string
 * @param string length
 */
void SSD1306_drawString(SSD1306_Dev* pDisplay, uint8_t pX, uint8_t pY, char* pString, uint8_t pLen);
/**
 * Draw string right aligned on display
 * @param pDisplay display handler
 * @param pX x coord
 * @param pY y coord
 * @param pString string
 * @param string length
 */
void SSD1306_drawStringRight(SSD1306_Dev* pDisplay, uint8_t pX, uint8_t pY, char* pString, uint8_t pLen);

/**
 * Get glyph of char
 * @param pGlyph character to find glyph
 * @return
 */
uint8_t* getGlyph(char pGlyph);


void FrameBuffer_drawPixel(uint8_t* pBuffer, uint8_t pX, uint8_t pY, uint8_t pOn);
void FrameBuffer_drawVLine(uint8_t* pBuffer, uint8_t pX, uint8_t pY, uint8_t pLength);
void FrameBuffer_drawHLine(uint8_t* pBuffer, uint8_t pX, uint8_t pY, uint8_t pLength);
void FrameBuffer_drawGlyph(uint8_t* pBuffer, uint8_t pX, uint8_t pY, uint8_t* pGlyph);
void FrameBuffer_drawChar(uint8_t* pBuffer, uint8_t pX, uint8_t pY, char pChar);
void FrameBuffer_drawString(uint8_t* pBuffer, uint8_t pX, uint8_t pY, char* pString, uint8_t pLen);
#endif //OLED_SSD1306_H
