/**
 * GameController.h
 * Header file
 *
 * A game controller which controls the current playing game.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Game.h"
#include "DrawPipe.h"

/**
 * GameController class.
 * 
 * @package core
 * @author Tim Visee
 */
class GameController {
private:
	/** Instance of the current running game. */
	Game g;
	/** Defines whether a game has been set. True if a game has been set, false otherwise. */
	bool gSet;

public:
	/**
	 * Constructor.
	 */
	GameController();

	/**
	 * Constructor.
	 *
	 * @param g The instance of the game to run.
	 */
	GameController(Game g);

	/**
	 * Get the instance of the current running game.
	 * 
	 * @return Instance of the current running game.
	 */
	Game * getGame();

	/**
	 * Set the current running game.
	 *
	 * @param g Instance of the game to run.
	 *
	 * @return True on success, false on failure.
	 */
	bool setGame(Game g);

	/**
	 * Chech whether a game has been set to run.
	 *
	 * @return True if a game has been set, false otherwise.
	 */
	bool isGameSet();

	/**
	 * Fire a game update.
	 *
	 * @return True on success, false on failure. False will also be returned if no game was set yet.
	 */
	bool updateGame();

	/**
	 * Render the game.
	 *
	 * @param dp Reference to a draw pipe that needs to be used to draw on the display.
	 *
	 * @return True on success, false on failure. False will also be returned if no game was set yet.
	 */
	bool renderGame(DrawPipe * dp);
};

#endif