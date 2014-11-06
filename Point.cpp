/**
 * Point.cpp
 * Source file
 *
 * Point class, representing a point in a 2D space.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "Point.h"

Point::Point() {
	// Set the field defaults
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::getX() {
	return this->x;
}

void Point::setX(int x) {
	this->x = x;
}

int Point::getY() {
	return this->y;
}

void Point::setY(int y) {
	this->y = y;
}