/**
 * Car.cpp
 * Source file
 *
 * A car object.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "Car.h"

Rect Car::getHitbox() {
	return Rect(0, 0, CAR_WIDTH, CAR_HEIGHT);
}

bool Car::drawCar(DrawPipe * dp, int pos) {
	/** Defines the car x position. */
	int x = pos;
	/** Defines the car y position. */
	int y = 4;
	/** Defines the length in x of the car */
	int xl = 6;
	/** Defines the length in y of the car */
	int yl = 3;

	/** Draw the car itself */
	dp->setColor(COLOR_GREEN);
	dp->drawRectFill(x + 1, y, x + xl - 1, y + yl);
	dp->drawPixel(x, y);
	dp->drawPixel(x, y + yl);
	dp->drawPixel(x + xl, y);
	dp->drawPixel(x + xl, y + yl);
	dp->setColor(COLOR_RED);
	dp->drawPixel(x, y + 1);
	dp->drawPixel(x, y + yl - 1);
	dp->setColor(COLOR_ORANGE);
	dp->drawPixel(x + xl, y + 1);
	dp->drawPixel(x + xl, y + yl - 1);
	dp->setColor(COLOR_GREEN);
}