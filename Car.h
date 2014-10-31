/**
 * Car.h
 * Header file
 *
 * A car object.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef CAR_H
#define CAR_H

#include "DrawPipe.h"
#include "Point.h"
#include "Rect.h"
#include "Viewport.h"

#define CAR_WIDTH 4
#define CAR_HEIGHT 6

/**
 * Car class.
 * 
 * @package core
 * @author Tim Visee
 */
class Car {
public:
	/** Defines the position of the car. */
	Point pos;

	/**
	 * Get the position car.
	 *
	 * @return Position of the car.
	 */
	Point getPosition();

	/**
	 * Get the rectangle hitbox of the car.
	 *
	 * @return Hitbox of the car as rectangle.
	 */
	Rect getHitbox();

	/**
	 * Draw the car using a display pipe.
	 *
	 * @param dp Display pipe reference to draw the car with.
	 * @param view The viewport reference.
	 * @param pos The position to draw the car at.
	 */
	bool drawCar(DrawPipe * dp, Viewport * view, int pos);
};

#endif