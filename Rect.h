/**
 * Rect.h
 * Header file
 *
 * A rectangle object.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef RECT_H
#define RECT_H

/**
 * Rect class.
 * 
 * @package core
 * @author Tim Visee
 */
class Rect {
private:
	/** The x coordinate of the rectangle. */
	int x;
	/** The y coordinate of the rectangle. */
	int y;
	/** The width of the rectangle. */
	int w;
	/** The height of the rectangle. */
	int h;

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
};

#endif