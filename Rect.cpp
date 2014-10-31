/**
 * Rect.cpp
 * Source file
 *
 * A rectangle object.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "Rect.h"

Rect::Rect() {
	// Set the field defaults
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}

int Rect::getX() {
	return this->x;
}

void Rect::setX(int x) {
	this->x = x;
}

int Rect::getY() {
	return this->y;
}

void Rect::setY(int y) {
	this->y = y;
}

int Rect::getWidth() {
	return this->w;
}

void Rect::setWidth(int w) {
	this->w = w;
}

int Rect::getHeight() {
	return this->h;
}

void Rect::setHeight(int h) {
	this->h = h;
}

int Rect::getSurface() {
	return this->w * this->h;
}