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
	this->roadOffset = 0;
	
	this->frogger = Frogger(Point(15, 0));

	// Instantiate all the roads
	for(int i = 0; i < FROGGER_ROAD_COUNT; i++)
		this->roads[i] = Road(4 + i * 5);

	this->dead = false;
	this->won = false;
	this->viewFade = 0;
}

bool FroggerGame::tick() {
	// Tick the road, return false on failure
	for(int i = 0; i < FROGGER_ROAD_COUNT; i++)
		if(!this->roads[i].tick())
			return false;

	// Check whether the frogger collides with any car
	if(this->isHitByCar())
		this->dead = true;

	if(this->viewFade > 0) {
		this->view.setY(this->view.getY() + 1);
		this->viewFade--;
	}

	// Return the result
	return true;
}

bool FroggerGame::update() {
	// Process the input
	if(this->input.goForward()) {
		this->frogger.forward();

		if(this->frogger.getPosition().getY() < 6)
			this->viewFade += 2;
		else
			this->viewFade += 5;
	}
	if(this->input.goLeft())
		this->frogger.left();
	if(this->input.goRight())
		this->frogger.right();

	if(this->frogger.getPosition().getY() > FROGGER_ROAD_COUNT * 5 + 2)
		this->won = true;

	// Return the result
	return true;
}

bool FroggerGame::render(DrawPipe * dp) {
	// Check whether the frogger won or died
	if(this->won) {
		dp->setColor(COLOR_GREEN);
		dp->drawRectFill(0, 0, 31, 15);
		return true;
	}
	if(this->dead) {
		dp->setColor(COLOR_RED);
		dp->drawRectFill(0, 0, 31, 15);
		return true;
	}

	// Draw the roads, return false on failure
	if(!this->drawRoad(dp))
		return false;

	// Draw the frog
	this->drawFrogger(dp);

	// Return the result
	return true;
}

bool FroggerGame::drawRoad(DrawPipe * dp) {
	// Draw the road, return the result
	for(int i = 0; i < FROGGER_ROAD_COUNT; i++)
		this->roads[i].draw(dp, &this->view);
	return true;
}

bool FroggerGame::isHitByCar() {
	// Check whether the frogger is hit by any car
	for(int i = 0; i < FROGGER_ROAD_COUNT; i++)
		if(this->roads[i].isHitByCar(&this->frogger))
			return true;

	// Frogger not hit, return false
	return false;
}

bool FroggerGame::drawFrogger(DrawPipe * dp) {
	return this->frogger.draw(dp, &this->view);
}