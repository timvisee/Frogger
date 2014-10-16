/**
 * DisplayDriver.cpp
 * Source file
 *
 * This is a driver to control an SURE (bi-color) LED matrix.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "DisplayDriver.h"

DisplayDriver::DisplayDriver() {
	// Set the default field values
	this->init();
}

DisplayDriver::DisplayDriver(int pinCs, int pinWrite, int pinData, int pinClock) {
	// Set the default field values
	this->init();

	// Set the pins
	this->setCsPin(pinCs);
	this->setWritePin(pinWrite);
	this->setDataPin(pinData);
	this->setClockPin(pinClock);
}

void DisplayDriver::init() {
	this->pinCs = 0;
	this->pinWrite = 0;
	this->pinData = 0;
	this->pinClock = 0;
	this->setupStatus = false;
	this->color = COLOR_GREEN;
}

int DisplayDriver::getCsPin() {
	return this->pinCs;
}

bool DisplayDriver::setCsPin(int pinCs) {
	// Make sure the value is different
	if(this->pinCs == pinCs)
		return true;

	// Keep track whether the display is being destroyed or not
	bool destroyed = false;

	// Change the pin
	this->pinCs = pinCs;

	// Check whether the display should be destroyed, return true if not
	if(!this->isSetup())
		return true;

	// Destroy the display, return the result
	this->destroy();
	return false;
}

int DisplayDriver::getWritePin() {
	return this->pinWrite;
}

bool DisplayDriver::setWritePin(int pinWrite) {
	// Make sure the value is different
	if(this->pinWrite == pinWrite)
		return true;

	// Keep track whether the display is being destroyed or not
	bool destroyed = false;

	// Change the pin
	this->pinWrite = pinWrite;

	// Check whether the display should be destroyed, return true if not
	if(!this->isSetup())
		return true;

	// Destroy the display, return the result
	this->destroy();
	return false;
}

int DisplayDriver::getDataPin() {
	return this->pinData;
}

bool DisplayDriver::setDataPin(int pinData) {
	// Make sure the value is different
	if(this->pinData == pinData)
		return true;

	// Keep track whether the display is being destroyed or not
	bool destroyed = false;

	// Change the pin
	this->pinData = pinData;

	// Check whether the display should be destroyed, return true if not
	if(!this->isSetup())
		return true;

	// Destroy the display, return the result
	this->destroy();
	return false;
}

int DisplayDriver::getClockPin() {
	return this->pinClock;
}

bool DisplayDriver::setClockPin(int pinClock) {
	// Make sure the value is different
	if(this->pinClock == pinClock)
		return true;

	// Keep track whether the display is being destroyed or not
	bool destroyed = false;

	// Change the pin
	this->pinClock = pinClock;

	// Check whether the display should be destroyed, return true if not
	if(!this->isSetup())
		return true;

	// Destroy the display, return the result
	this->destroy();
	return false;
}

Color DisplayDriver::getColor() {
	return this->color;
}

void DisplayDriver::setColor(Color color) {
	this->color = color;
}

bool DisplayDriver::setup() {
	// Make sure the display driver is valid
	if(!this->isValid())
		return false;
	
	// Connecting to the display, show a status message
	Logger::info("Connecting to display...");
	Logger::info(" (Pin configuration: CS " + String(this->getCsPin()) +
		", Write " + String(this->getWritePin()) +
		", Data " + String(this->getDataPin()) +
		", Clock " + String(this->getClockPin()) +
		")");

	// Set up the display
	HT1632.setCLK(this->getClockPin());
	HT1632.begin(this->getCsPin(), this->getWritePin(), this->getDataPin());

	// Connected, show a status message
	Logger::info("Connected to the display successfully!");

	// The display has been set up, return the result
	this->setupStatus = true;
	return true;
}

bool DisplayDriver::isSetup() {
	return this->setupStatus;
}

bool DisplayDriver::setSetup(bool setup) {
	// Make sure the set up status changed
	if(setup == this->setupStatus)
		return false;

	// Set the set up status and return the result
	this->setupStatus = setup;
	return true;
}

bool DisplayDriver::destroy() {
	// Make sure the display is set up
	if(!this->isSetup())
		return true;

	// Set the set up status of the display
	this->setSetup(false);
	return this->isSetup();
}

bool DisplayDriver::clear() {
	return this->clear(true);
}

bool DisplayDriver::clear(bool render) {
	// Make sure the display has been set up
	if(!this->isSetup())
		return false;

	// Flush the screen buffer
	HT1632.clear();

	// Render the screen
	if(render)
		HT1632.render();

	// The screen has been cleared, return the result
	return true;
}

bool DisplayDriver::render() {
	// Make sure the display has been set up
	if(!this->isSetup())
		return false;

	// Render the buffered screen, return the result
	HT1632.render();
	return true;
}

bool DisplayDriver::drawPixel(int x, int y) {
	// Make sure the display has been set up
	if(!this->isSetup())
		return false;

	// Draw the pixel, return the result
	if(this->getColor() == COLOR_GREEN || this->getColor() == COLOR_ORANGE) {
		HT1632.selectChannel(0);
		HT1632.drawImage(IMG_PIXEL, 1, 1, x, y);
	}
	if(this->getColor() == COLOR_RED || this->getColor() == COLOR_ORANGE) {
		HT1632.selectChannel(1);
		HT1632.drawImage(IMG_PIXEL, 1, 1, x, y);
	}
	return true;
}

bool DisplayDriver::drawLine(int x1, int y1, int x2, int y2) {
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = fabs(dx);
	dy1 = fabs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;

	if(dy1 <= dx1) {
		if(dx >= 0) {
			x = x1;
			y = y1;
			xe = x2;
		} else {
			x = x2;
			y = y2;
			xe = x1;
		}
		
		// Draw the pixel
		this->drawPixel(x, y);

		for(i = 0; x < xe; i++) {
			x = x + 1;

			if(px < 0)
				px = px + 2 * dy1;

			else {
				if((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					y = y + 1;
				else
					y = y - 1;
				px = px + 2 * (dy1 - dx1);
			}

			// Draw the pixel
			this->drawPixel(x, y);
		}

	} else {
		if(dy >= 0) {
			x = x1;
			y = y1;
			ye = y2;
		} else {
			x = x2;
			y = y2;
			ye = y1;
		}
		
		// Draw the pixel
		this->drawPixel(x, y);

		for(i = 0; y < ye; i++) {
			y = y + 1;

			if(py <= 0)
				py = py + 2 * dx1;

			else {
				if((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					x = x + 1;
				else
					x = x - 1;

				py = py + 2 * (dx1 - dy1);
			}
			
			// Draw the pixel
			this->drawPixel(x, y);
		}
	}
}

bool DisplayDriver::drawRect(int x1, int y1, int x2, int y2) {
	// Get the minimum and maximum coordinate values
	int xMin = min(x1, x2);
	int yMin = min(y1, y2);
	int xMax = max(x1, x2);
	int yMax = max(y1, y2);
	
	// Draw the rectangle
	this->drawLine(xMin, yMin, xMin, yMax);
	this->drawLine(xMin, yMin, xMax, yMin);
	this->drawLine(xMin, yMax, xMax, yMax);
	this->drawLine(xMax, yMin, xMax, yMax);

	// Rectangle drawn, return the result
	return true;
}

bool DisplayDriver::isValid() {
	// Validate the display pins
	if(!this->isValidPin(this->pinCs) || !this->isValidPin(this->pinWrite) || !this->isValidPin(this->pinData) || !this->isValidPin(this->pinClock))
		return false;

	// The driver seems to be set up correctly, return the result
	return true;
}

bool DisplayDriver::isValidPin(int pin) {
	return (pin > 0 && pin < 52);
}
