/**
 * Point.h
 * Header file
 *
 * Point, class representing a point in a 2D space.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef POINT_H
#define POINT_H

/**
 * Point class.
 * 
 * @package core
 * @author Tim Visee
 */
class Point {
private:
	/** The x coordinate of the rectangle. */
	int x;
	/** The y coordinate of the rectangle. */
	int y;

public:
	/**
	 * Constructor.
	 */
	Point();

	/**
	 * Constructor.
	 *
	 * @param x X coordinate.
	 * @param y Y coordinate.
	 */
	Point(int x, int y);

	/**
	 * Get the x coordinate of the rectangle.
	 *
	 * @return X coordinate of the rectangle.
	 */
	int getX();

	/**
	 * Set the x coordinate of the rectangle.
	 *
	 * @param x X coordinate of the rectangle.
	 */
	void setX(int x);
	
	/**
	 * Get the y coordinate of the rectangle.
	 *
	 * @return Y coordinate of the rectangle.
	 */
	int getY();

	/**
	 * Set the y coordinate of the rectangle.
	 *
	 * @param y Y coordinate of the rectangle.
	 */
	void setY(int y);
};

#endif