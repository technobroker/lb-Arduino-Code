////////////////////////////////////////////////////////////////////////////
//  MyMenu.h - Library for MyMenu Shield
//  Created by Douglas Gilliland. 2012-07-27
////////////////////////////////////////////////////////////////////////////
// Pin assignments as referenced to the MyMenu Board
// 
////////////////////////////////////////////////////////////////////////////

#ifndef MyMenu_h
#define MyMenu_h

#include <inttypes.h>
#include <../Adafruit_MCP23008/Adafruit_MCP23008.h>

////////////////////////////////////////////////////////////////////////////////////
// enums follow
////////////////////////////////////////////////////////////////////////////////////

enum KEY_PRESSES
{
  NONE,
  RIGHT,
  UP,
  DOWN,
  LEFT,
  SELECT,
};
#define GRN_LITE 5   // pwmable
#define RED_LITE 6   // pwmable

////////////////////////////////////////////////////////////////////////////
// I2C Ports
//	OLED 0x78 (typical)
//	MCP23008 0x20
////////////////////////////////////////////////////////////////////////////

class MyMenu
{
  public:
    MyMenu(void);
    uint8_t pollKeypad(void);
    void waitForKeyRelease(void);
    uint8_t getKeyPressed(void);
    uint8_t waitKeyPressed(void);
    uint8_t delayAvailable(int delayTime);
	void setLED(int ledNum, int val);
  private:
    void initPins(void);
	Adafruit_MCP23008 mcp;
};

#endif
