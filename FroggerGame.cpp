#include "FroggerGame.h"

FroggerGame::FroggerGame() {
	this->pos = 7;
}

bool FroggerGame::tick() {
	// Write a status message to the console
	
	this->pos++;
	this->pos = this->pos % 16;

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
	// Draw random pixels, for debugging
	/*for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 16; j++) {
			dp->setColor(static_cast<Color>(random(0, 4)));
			dp->drawPixel(i, j);
		}
	}*/

	dp->drawPixel(7, this->pos);

	// Return the result
	return true;
}