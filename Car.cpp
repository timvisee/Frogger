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

Car::Car() {
	// Set the field defaults
	this->pos = Point();
}

Car::Car(Point pos) {
	this->pos = pos;
}

Point Car::getPosition() {
	return this->pos;
}

void Car::setPosition(Point pos) {
	this->pos = pos;
}

void Car::move(Direction dir) {
	return this->move(dir, 1);
}

void Car::move(Direction dir, int distance) {
	if(dir == DIRECTION_LEFT)
		this->pos.setX(this->pos.getX() - distance);
	else
		this->pos.setX(this->pos.getX() + distance);
}

Rect Car::getHitbox() {
	return Rect(this->pos.getX(), this->pos.getY(), CAR_WIDTH, CAR_HEIGHT);
}

bool Car::drawCar(DrawPipe * dp, Viewport * view, Direction dir) {
	/** Defines the car x position. */
	int x = -view->getX() + this->pos.getX();
	/** Defines the car y position. */
	int y = -view->getY() + this->pos.getY();
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
	if(dir == DIRECTION_RIGHT)
		dp->setColor(COLOR_RED);
	else
		dp->setColor(COLOR_ORANGE);
	dp->drawPixel(x, y + 1);
	dp->drawPixel(x, y + yl - 1);
	if(dir == DIRECTION_RIGHT)
		dp->setColor(COLOR_ORANGE);
	else
		dp->setColor(COLOR_RED);
	dp->drawPixel(x + xl, y + 1);
	dp->drawPixel(x + xl, y + yl - 1);
	dp->setColor(COLOR_GREEN);
}