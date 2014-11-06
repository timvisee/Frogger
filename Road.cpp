/**
 * Road.cpp
 * Source file
 *
 * Road class, representing a road object.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "Road.h"

Road::Road() {
	// Set the field defaults
	this->count = 0;
	this->dir = static_cast<Direction>(random(0, 2));
}

Road::Road(int pos) {
	this->count = 0;
	this->pos = pos;
	this->dir = static_cast<Direction>(random(0, 2));
}

int Road::getCarCount() {
	return this->count;
}

Direction Road::getDirection() {
	return this->dir;
}

void Road::setDirection(Direction dir) {
	this->dir = dir;
}

bool Road::spawnCar() {
	// Make sure there aren't 3 cars on the road already
	if(this->count >= 3)
		return false;

	// Make sure we aren't spawning a car inside another
	if(this->count > 0) {
		if(this->dir == DIRECTION_RIGHT) {
			if(this->cars[this->count - 1].getPosition().getX() <= 2)
				return false;
		} else {
			if(this->cars[this->count - 1].getPosition().getX() >= 24)
				return false;
		}
	}

	// Spawn the car
	if(this->dir == DIRECTION_RIGHT)
		this->cars[this->count] = Car(Point(-6, this->pos + 1));
	else
		this->cars[this->count] = Car(Point(32, this->pos + 1));
	this->count++;
}

bool Road::destroyCar(int i) {
	// Make sure a car with this index is available
	if((this->count - 1) < i)
		return false;

	// Move the next cars one place down
	for(int i = 0; i < this->count - 1; i++)
		this->cars[i] = this->cars[i + 1];

	// Decrease the carcount number 
	this->count--;
	return true;
}

bool Road::tick() {
	// Move the cars in the proper direction
	if(this->count > 0)
		for(int i = 0; i < this->count; i++)
			this->cars[i].move(this->dir);

	// Spawn random cars
	if(random(0, 45) == 0)
		this->spawnCar();

	// Destroy cars that aren't visible anymore
	if(this->count > 0) {
		for(int i = this->count; i >= 0; i--) {
			if(this->dir == DIRECTION_RIGHT) {
				if(this->cars[i].getPosition().getX() > 32)
					this->destroyCar(i);
			} else {
				if(this->cars[i].getPosition().getX() < -6)
					this->destroyCar(i);
			}
		}
	}

	// Return the result
	return true;
}

bool Road::draw(DrawPipe * dp, Viewport * view) {
	// Draw the road lines
	dp->setColor(COLOR_ORANGE);
	
	int yrow = this->pos + -view->getY();
	int x1 = -view->getX();

	int x2 = -view->getX() + 31;

	for(int y = yrow; y <= yrow + 5; y += 5)
		for(int x = x1; x <= x2; x++)
			if((x % 5) < 4)
				dp->drawPixel(x, y);

	// Draw the cars on the road
	if(this->count > 0)
		for(int i = 0; i < this->count; i++)
			this->cars[i].drawCar(dp, view, this->dir);
	
	// Return the result
	return true;
}

bool Road::isHitByCar(Frogger * frogger) {
	// Check whether the frogger is hit by any of the cars
	for(int i = 0; i < this->count; i++)
		if(frogger->getHitbox().isOverlapping(&this->cars[i].getHitbox()))
			return true;

	// Frogger not hit, return false
	return false;
}