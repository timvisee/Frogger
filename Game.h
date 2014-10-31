/**
 * Game.h
 * Header file
 *
 * A game class, which is the base for various games.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef GAME_H
#define GAME_H

#include "Arduino.h"
#include "DrawPipe.h"

/**
 * Game class.
 * 
 * @package core
 * @author Tim Visee
 */
class Game {
public:
	/**
	 * Called once each tick.
	 *
	 * @return True on success, false on failure.
	 */
	virtual bool tick();

	/**
	 * Called once each game update.
	 *
	 * @return True on success, false on failure.
	 */
	virtual bool update();

	/**
	 * Called when the game should be rendered.
	 *
	 * @param dp Reference to a draw pipe that needs to be used to draw on the display.
	 *
	 * @return True on success, false on failure.
	 */
	virtual bool render(DrawPipe * dp);
};

#endif