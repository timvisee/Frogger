/**
 * FroggerClass.cpp
 * Source file
 *
 * Frogger class, representing the frogger object.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "FroggerClass.h"

Frogger::Frogger() {
	this->setPosition(Point());
}

Frogger::Frogger(Point pos) {
	this->setPosition(pos);
}

Point Frogger::getPosition() {
	return this->pos;
}

void Frogger::setPosition(Point pos) {
	this->pos = pos;
}

Rect Frogger::getHitbox() {
	return Rect(this->getPosition(), Point(3, 3));
}

bool Frogger::forward() {
	this->pos.setY(this->pos.getY() + 5);
}

bool Frogger::left() {
	if(this->pos.getX() > 0)
		this->pos.setX(this->pos.getX() - 1);
}

bool Frogger::right() {
	if(this->pos.getX() < 29)
		this->pos.setX(this->pos.getX() + 1);
}

bool Frogger::draw(DrawPipe * dp, Viewport * view) {
	// Draw the body
	dp->setColor(COLOR_GREEN);
	dp->drawRectFill(-view->getX() + this->pos.getX(), this->pos.getY() + -view->getY(), this->pos.getX() + -view->getX() + 2, this->pos.getY() + -view->getY() + 2);
	
	// Draw the eyes
	dp->setColor(COLOR_RED);
	if(millis() % 1000 < 500) {
		dp->drawPixel(this->pos.getX() + -view->getX(), this->pos.getY() + -view->getY() + 2);
		dp->drawPixel(this->pos.getX() + -view->getX() + 2, this->pos.getY() + -view->getY() + 2);
	}
}