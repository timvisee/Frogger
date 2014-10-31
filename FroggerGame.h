/**
 * FroggerGame.h
 * Header file
 *
 * Frogger game.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef FROGGERGAME_H
#define FROGGERGAME_H

#include "Rect.h"
#include "Viewport.h"
// TODO: Is Game.h still required?
#include "Game.h"
#include "Car.h"
#include "Arduino.h"

/**
 * FroggerGame class.
 * 
 * @package core
 * @author Tim Visee
 */
class FroggerGame {
private:
	Viewport view;

	int pos;
	int roadOffset;
	Car c;

public:
	FroggerGame();

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

	void drawRoad(DrawPipe * dp);
	void drawFrog(DrawPipe * dp);
	void drawCar(DrawPipe * dp);
};

#endif