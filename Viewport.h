/**
 * Viewport.h
 * Header file
 *
 * This class represents a viewport.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Rect.h"

class Viewport {
private:
	Rect view;

public:
	/**
	 * Constructor.
	 */
	Viewport();

	/**
	 * Constructor.
	 *
	 * @param w Viewport width
	 * @param h Viewport height
	 */
	Viewport(int w, int h);
	
	/**
	 * Constructor.
	 *
	 * @param size The size of the viewport.
	 */
	Viewport(Point size);
	
	/**
	 * Constructor.
	 *
	 * @param view The rectangle that represents the viewport.
	 */
	Viewport(Rect view);

	/**
	 * Constructor.
	 *
	 * @param x Viewport x
	 * @param y Viewport y
	 * @param w Viewport width
	 * @param h Viewport height
	 */
	Viewport(int x, int y, int w, int h);

	/**
	 * Constructor.
	 *
	 * @param pos Position of the viewport.
	 * @param size Size of the viewport.
	 */
	Viewport(Point pos, Point size);

	/**
	 * Get the view as a rectangle.
	 */
	Rect getView();

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
};

#endif