/**
 * FroggerClass.h
 * Header file
 *
 * Frogger Class, class representing the frogger object.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef FROGGER_H
#define FROGGER_H

#include "Point.h"
#include "Rect.h"
#include "DrawPipe.h"
#include "Viewport.h"

/**
 * FroggerClass class.
 * 
 * @package core
 * @author Tim Visee
 */
class Frogger {
private:
	/** Defines the position of the frogger. */
	Point pos;

public:
	/**
	 * Constructor.
	 */
	Frogger();

	/**
	 * Constructor.
	 *
	 * @param pos The position of the frogger at start.
	 */
	Frogger(Point pos);

	/**
	 * Get the position of the frogger.
	 *
	 * @return The position of the frogger.
	 */
	Point getPosition();

	/**
	 * Set the position of the frogger.
	 *
	 * @param pos The position of the frogger.
	 */
	void setPosition(Point pos);

	/**
	 * Get the hitbox of the frog as an rectangle.
	 *
	 * @return Hitbox of the frog.
	 */
	Rect getHitbox();

	bool forward();
	bool left();
	bool right();

	/**
	 * Draw the frog with the specified drawpipe in the viewport.
	 *
	 * @param dp The drawpipe reference to draw with.
	 * @param view The viewport
	 *
	 * @return True on success, false on failure.
	 */
	bool draw(DrawPipe * dp, Viewport * view);
};

#endif