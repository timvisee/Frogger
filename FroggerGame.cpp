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
	this->view = Viewport(0, 0, 32, 16);
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
	dp->drawLine(-this->view.getX() + 0, -this->view.getY() + 3, -this->view.getX() + 31, -this->view.getY() + 3);
	dp->drawLine(-this->view.getX() + 0, -this->view.getY() + 8, -this->view.getX() + 31, -this->view.getY() + 8);
	dp->drawLine(-this->view.getX() + 0, -this->view.getY() + 13, -this->view.getX() + 31, -this->view.getY() + 13);
}

void FroggerGame::drawFrog(DrawPipe * dp) {
	dp->setColor(COLOR_GREEN);
	dp->drawRect(-this->view.getX() + 10, -this->view.getY() + 10, -this->view.getX() + 12, -this->view.getY() + 12);
	dp->drawPixel(-this->view.getX() + 11, -this->view.getY() + 11);
	dp->setColor(COLOR_RED);

	if(millis() % 1000 < 500) {
		dp->drawPixel(-this->view.getX() + 10, -this->view.getY() + 10);
		dp->drawPixel(-this->view.getX() + 12, -this->view.getY() + 10);
	}
}

void FroggerGame::drawCar(DrawPipe * dp) {
	this->c.drawCar(dp, &this->view, this->pos);
}