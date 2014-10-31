/**
 * FroggerGame.cpp
 * Source file
 *
 * Frogger game.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "FroggerGame.h"

FroggerGame::FroggerGame() {
	this->pos = 7;
	this->roadOffset = 0;
}

bool FroggerGame::tick() {
	// Write a status message to the console
	this->pos++;
	this->pos = ((this->pos + 6) % 38) - 6;

	// Return the result
	return true;
}

bool FroggerGame::update() {
	// Write a status message to the console
	//Logger::debug("FroggerGame update called!");

	// Return the result
	return true;
}

bool FroggerGame::render(DrawPipe * dp) {
	/* // Draw random pixels, for debugging
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 16; j++) {
			dp->setColor(static_cast<Color>(random(0, 4)));
			dp->drawPixel(i, j);
		}
	}*/

	// Draw the roads
	this->drawRoad(dp);

	this->drawFrog(dp);

	this->drawCar(dp);

	//dp->drawPixel(7, this->pos);*/

	// Return the result
	return true;
}

void FroggerGame::drawRoad(DrawPipe * dp) {
	dp->setColor(COLOR_ORANGE);
	dp->drawLine(0, 3, 31, 3);
	dp->drawLine(0, 8, 31, 8);
	dp->drawLine(0, 13, 31, 13);
}

void FroggerGame::drawFrog(DrawPipe * dp) {
	dp->setColor(COLOR_GREEN);
	dp->drawRect(10, 10, 12, 12);
	dp->drawPixel(11, 11);
	dp->setColor(COLOR_RED);

	if(millis() % 1000 < 500) {
		dp->drawPixel(10, 10);
		dp->drawPixel(12, 10);
	}
}

void FroggerGame::drawCar(DrawPipe * dp) {
	this->c.drawCar(dp, this->pos);
}