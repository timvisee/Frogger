/**
 * DrawPipe.cpp
 * Source file
 *
 * The draw pipe is used to draw graphical shapes on the display.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "DrawPipe.h"

DrawPipe::DrawPipe() {
	this->driverSet = false;
}

DrawPipe::DrawPipe(DisplayDriver * driver) {
	this->driver = driver;
	this->driverSet = true;
}

bool DrawPipe::drawPixel(int x, int y) {
	// Make sure the display driver is valid
	if(!this->isValid())
		return false;

	return this->driver->drawPixel(x, y);
}

bool DrawPipe::drawLine(int x1, int y1, int x2, int y2) {
	// Make sure the display driver is valid
	if(!this->isValid())
		return false;

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
		if(!this->drawPixel(x, y))
			return false;

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
			if(!this->drawPixel(x, y))
				return false;
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
		if(!this->drawPixel(x, y))
			return false;

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
			if(!this->drawPixel(x, y))
				return false;
		}
	}

	// The line has been drawn successfully, return the result
	return true;
}

bool DrawPipe::drawRect(int x1, int y1, int x2, int y2) {
	// Make sure the display driver is valid
	if(!this->isValid())
		return false;

	// Get the minimum and maximum coordinate values
	int xMin = min(x1, x2);
	int yMin = min(y1, y2);
	int xMax = max(x1, x2);
	int yMax = max(y1, y2);
	
	// Draw the rectangle
	if(!this->drawLine(xMin, yMin, xMin, yMax))
		return false;
	if(!this->drawLine(xMin, yMin, xMax, yMin))
		return false;
	if(!this->drawLine(xMin, yMax, xMax, yMax))
		return false;
	if(!this->drawLine(xMax, yMin, xMax, yMax))
		return false;

	// Rectangle drawn, return the result
	return true;
}

Color DrawPipe::getColor() {
	return this->driver->getColor();
}

bool DrawPipe::setColor(Color color) {
	// Make sure the display driver is valid
	if(!this->isValid())
		return false;

	// Set the color, return the result
	this->driver->setColor(color);
	return true;
}

bool DrawPipe::isValid() {
	return this->driverSet;
}