#ifndef ROAD_H
#define ROAD_H

#include "Arduino.h"
#include "DrawPipe.h"
#include "Viewport.h"
#include "Car.h"
#include "Direction.h"
#include "FroggerClass.h"

class Road {
private:
	int pos;
public:
	Car cars[3];
private:
	int count;
	Direction dir;

public:
	/**
	 * Constructor.
	 */
	Road();

	/**
	 * Constructor.
	 *
	 * @param pos Road position.
	 */
	Road(int pos);

	/**
	 * Get the car count.
	 */
	int getCarCount();

	/**
	 * Get the direction of the cars moving.
	 *
	 * @return The direction of the cars moving.
	 */
	Direction getDirection();

	/**
	 * Set the direction of the cars moving.
	 *
	 * @param dir The diretion of the cars moving.
	 */
	void setDirection(Direction dir);

	/**
	 * Spawn a new car on the road.
	 *
	 * @return True on success, false on failure if the car couldn't spawn.
	 */
	bool spawnCar();

	/**
	 * Destroy the car with the specified index.
	 *
	 * @param i The index of the car to destroy.
	 *
	 * @return True on success, false on failure.
	 */
	bool destroyCar(int i);

	/**
	 * Called once each game tick.
	 *
	 * @return True if succeed, false otherwise.
	 */
	bool tick();
	
	/**
	 * Draw the road and the cars driving on it.
	 *
	 * @param dp Drawpipe reference to use to draw the road and cars.
	 * @param view Viewport referene to determine where to draw the road and cars.
	 */
	bool draw(DrawPipe * dp, Viewport * view);

	/**
	 * Check whether the frogger is hit by any car on this road.
	 *
	 * @param frogger The frogger reference.
	 *
	 * @return True if the frogger is hit by any car, false otherwise.
	 */
	bool isHitByCar(Frogger * frogger);
};

#endif