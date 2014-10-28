/**
 * GameController.cpp
 * Source file
 *
 * A game controller which controls the current playing game.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "GameController.h"

GameController::GameController() {
	// Field defaults
	this->gSet = false;
}

GameController::GameController(Game g) {
	// Set the game instance
	this->setGame(g);
}

Game * GameController::getGame() {
	return &this->g;
}

bool GameController::setGame(Game g) {
	// Set the game instance
	this->g = g;
	this->gSet = true;

	// Return the result
	return true;
}

bool GameController::isGameSet() {
	return this->gSet;
}

bool GameController::updateGame() {
	// Make sure the game is set
	if(!this->isGameSet())
		return false;

	// Update the game, return the result
	return this->g.update();
}

bool GameController::renderGame(DrawPipe * dp) {
	// Make sure the game is set
	if(!this->isGameSet())
		return false;

	// Render the game, return the result
	return this->g.render(dp);
}