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
#include "Road.h"
#include "FroggerClass.h"
#include "Arduino.h"
#include "InputManager.h"

#define FROGGER_ROAD_COUNT 20

/**
 * FroggerGame class.
 * 
 * @package core
 * @author Tim Visee
 */
class FroggerGame {
private:
	Viewport view;
	Frogger frogger;
	int roadOffset;
	Road roads[FROGGER_ROAD_COUNT];
	bool dead;
	bool won;
	InputManager input;
	int viewFade;

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

	bool drawRoad(DrawPipe * dp);

	/**
	 * Check whether the frogger is hit by a car or not.
	 *
	 * @return True if the forgger is currently hit, false otherwise.
	 */
	bool isHitByCar();

	/**
	 * Draw the frogger.
	 *
	 * @param dp The draw pipe instance to draw the frogger with.
	 *
	 * @return True on success, false on failure.
	 */
	bool drawFrogger(DrawPipe * dp);
};

#endif