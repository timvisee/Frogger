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
	this->pos = Point();
	this->size = Point();
}

Rect::Rect(int x, int y, int w, int h) {
	this->pos.setX(x);
	this->pos.setY(y);
	this->size.setX(w);
	this->size.setY(h);
}

Rect::Rect(Point pos, Point size) {
	this->pos = pos;
	this->size = size;
}

Point Rect::getPosition() {
	return this->pos;
}

void Rect::setPosition(Point pos) {
	this->pos = pos;
}

int Rect::getX() {
	return this->pos.getX();
}

void Rect::setX(int x) {
	this->pos.setX(x);
}

int Rect::getY() {
	return this->pos.getY();
}

void Rect::setY(int y) {
	this->pos.setY(y);
}

Point Rect::getSize() {
	return this->size;
}

void Rect::setSize(Point size) {
	this->size = size;
}

int Rect::getWidth() {
	return this->size.getX();
}

void Rect::setWidth(int w) {
	this->size.setX(w);
}

int Rect::getHeight() {
	return this->size.getY();
}

void Rect::setHeight(int h) {
	this->size.setY(h);
}

int Rect::getSurface() {
	return this->getWidth() * this->getHeight();
}