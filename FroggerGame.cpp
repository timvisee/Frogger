#include "FroggerGame.h"

bool Game::update() {
	// Write a status message to the console
	Logger::debug("FroggerGame update called!");

	// Return the result
	return true;
}

bool Game::render(DrawPipe * dp) {
	// Draw random pixels, for debugging
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < 16; j++) {
			dp->setColor(static_cast<Color>(random(0, 4)));
			dp->drawPixel(i, j);
		}
	}

	// Return the result
	return true;
}