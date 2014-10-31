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
#include "Direction.h"

#define CAR_WIDTH 6
#define CAR_HEIGHT 4

/**
 * Car class.
 * 
 * @package core
 * @author Tim Visee
 */
class Car {
private:
	/** Defines the position of the car. */
	Point pos;

public:
	/**
	 * Constructor.
	 */
	Car();

	/**
	 * Constructor.
	 *
	 * @param pos The position of the car.
	 */
	Car(Point pos);

	/**
	 * Get the position car.
	 *
	 * @return Position of the car.
	 */
	Point getPosition();

	/**
	 * Set the position of the car.
	 *
	 * @param pos The position of the car. =
	 */
	void setPosition(Point pos);

	/**
	 * Move the car one position to the specified direction.
	 *
	 * @param dir The direction to move the car to.
	 */
	void move(Direction dir);

	/**
	 * Move the car to the specified direction with a specified distance.
	 *
	 * @param dir The direction to move the car to.
	 * @param distance The distance to move the car.
	 */
	void move(Direction dir, int distance);

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
	 * @param dir The direction the car is facing.
	 */
	bool drawCar(DrawPipe * dp, Viewport * view, Direction dir);
};

#endif