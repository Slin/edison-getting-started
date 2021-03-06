#include <iostream>
#include "submodules/block_oled/Firmware/pong/oled/Edison_OLED.h"
#include "submodules/block_oled/Firmware/pong/gpio/gpio.h"
#include "math.h"
#include <stdio.h>

using namespace std;

// Function prototypes:
void setupOLED();
void startScreen();

void drawGame();
void cleanUp();

// Define an edOLED object:
edOLED oled;

// Pin definitions:
// All buttons have pull-up resistors on-board, so just declare
// them as regular INPUT's
gpio BUTTON_UP(47, INPUT);
gpio BUTTON_DOWN(44, INPUT);
gpio BUTTON_LEFT(165, INPUT);
gpio BUTTON_RIGHT(45, INPUT);
gpio BUTTON_SELECT(48, INPUT);
gpio BUTTON_A(49, INPUT);
gpio BUTTON_B(46, INPUT);


int main(int argc, char * argv[])
{
	printf("WASSUP!?\r\n");

	setupOLED();

	while(BUTTON_A.pinRead() != HIGH){}

	while(BUTTON_A.pinRead() == HIGH)
	{
		drawGame();
	}

	cleanUp();
	return 0;
}

void setupOLED()
{
	oled.begin();
	oled.clear(PAGE);
	oled.display();
	oled.setFontType(0);
}

// Draw the paddles, ball and score:
void drawGame()
{
	oled.clear(PAGE);
	
	oled.rectFill(0, 0, oled.getLCDWidth(), oled.getLCDHeight());

	oled.display();
}

void cleanUp()
{
	oled.clear(PAGE);
	oled.display();
}
