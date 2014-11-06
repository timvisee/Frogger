/**
 * Rect.h
 * Header file
 *
 * A rectangle object.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef RECT_H
#define RECT_H

#include "Point.h"

/**
 * Rect class.
 * 
 * @package core
 * @author Tim Visee
 */
class Rect {
private:
	/** Defines the position of the rectangle. */
	Point pos;
	/** Defines the size of the rectangle. */
	Point size;

public:
	/**
	 * Constructor.
	 */
	Rect();

	/**
	 * Constructor.
	 *
	 * @param x X coordinate.
	 * @param y Y coordinate.
	 * @param w Rectangle width.
	 * @param h Rectangle height.
	 */
	Rect(int x, int y, int w, int h);
	
	/**
	 * Constructor.
	 *
	 * @param pos The position of the rectangle.
	 * @param size The size of the rectangle.
	 */
	Rect(Point pos, Point size);

	/**
	 * Get the position of the rectangle as a point.
	 *
	 * @return Position of the rectangle.
	 */
	Point getPosition();

	/**
	 * Set the position of the rectangle.
	 *
	 * @param pos The position of the rectangle.
	 */
	void setPosition(Point pos);

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

	/**
	 * Get the size of the rectangle, as a point.
	 *
	 * @param The size of the rectangle.
	 */
	Point getSize();

	/**
	 * Set the size of the rectangle.
	 *
	 * @param size Size of the rectangle.
	 */
	void setSize(Point size);

	/**
	 * Get the width of the rectangle.
	 *
	 * @return With of the rectangle.
	 */
	int getWidth();

	/**
	 * Set the width of the rectangle.
	 *
	 * @param w Width of the rectangle.
	 */
	void setWidth(int w);
	
	/**
	 * Get the height of the rectangle.
	 *
	 * @return Height of the rectangle.
	 */
	int getHeight();
	
	/**
	 * Set the height of the rectangle.
	 *
	 * @param h Height of the rectangle.
	 */
	void setHeight(int h);

	/**
	 * Get the surface area of the rectangle.
	 *
	 * @return Surface area of the rectangle.
	 */
	int getSurface();

	/**
	 * Check whether two rectangles are overlapping each other.
	 *
	 * @param other The other rectangle to check for overlapping with the current
	 *
	 * @return True if the rectangles are overlapping, false otherwise.
	 */
	bool isOverlapping(Rect * other);
};

#endif