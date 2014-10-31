#ifndef FROGGERGAME_H
#define FROGGERGAME_H

#include "Game.h"
#include "Arduino.h"

class FroggerGame : public Game {
	/**
	 * Called once each tick.
	 *
	 * @return True on success, false on failure.
	 */
	bool tick();

	/**
	 * Called once each game update.
	 *
	 * @return True on success, false on failure.
	 */
	bool update();

	/**
	 * Called when the game should be rendered.
	 *
	 * @param dp Reference to a draw pipe that needs to be used to draw on the display.
	 *
	 * @return True on success, false on failure.
	 */
	bool render(DrawPipe * dp);
};

#endif