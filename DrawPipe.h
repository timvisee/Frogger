/**
 * DrawPipe.h
 * Header file
 *
 * The draw pipe is used to draw graphical shapes on the display.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef DRAWPIPE_H
#define DRAWPIPE_H

#include "DisplayDriver.h"

/**
 * DrawPipe class.
 * 
 * @package core
 * @author Tim Visee
 */
class DrawPipe {
private:
	/** Display driver instance. */
	DisplayDriver * driver;
	/** Defines whether the display driver instance has been set. */
	bool driverSet;

public:
	/**
	 * Constructor.
	 */
	DrawPipe();

	/**
	 * Constructor.
	 *
	 * @param driver Display driver instance.
	 */
	DrawPipe(DisplayDriver * driver);

	/**
	 * Draw a pixel at the specified location.
	 *
	 * @param x The x coordinate of the pixel to draw.
	 * @param y The y coordinate of the pixel to draw.
	 *
	 * @return True on success, false on failure.
	 */
	bool drawPixel(int x, int y);
	
	/**
	 * Draw a line at the specified location.
	 *
	 * @param x1 The x coordinate of the first point.
	 * @param y1 The y coordinate of the first point.
	 * @param x2 The x coordinate of the last point.
	 * @param y2 The y coordinate of the last point.
	 *
	 * @return True on succes, false on failure.
	 */
	bool drawLine(int x1, int y1, int x2, int y2);

	/**
	 * Draw a rectangle at the specified location.
	 *
	 * @param x1 The x coordinate of the first corner.
	 * @param y1 The y coordinate of the first corner.
	 * @param x2 The x coordinate of the last corner.
	 * @param y2 The y coordinate of the last corner.
	 *
	 * @return True on success, false on failure.
	 */
	bool drawRect(int x1, int y1, int x2, int y2);

	/**
	 * Draw a filled rectangle at the specified location.
	 *
	 * @param x1 The x coordinate of the first corner.
	 * @param y1 The y coordinate of the first corner.
	 * @param x2 The x coordinate of the last corner.
	 * @param y2 The y coordinate of the last corner.
	 *
	 * @return True on success, false on failure.
	 */
	bool drawRectFill(int x1, int y1, int x2, int y2);

	/**
	 * Draw a filled rectangle at the specified location.
	 *
	 * @param x1 The x coordinate of the first corner.
	 * @param y1 The y coordinate of the first corner.
	 * @param x2 The x coordinate of the last corner.
	 * @param y2 The y coordinate of the last corner.
	 * @param fill The fill color to use.
	 *
	 * @return True on success, false on failure.
	 */
	bool drawRectFill(int x1, int y1, int x2, int y2, Color fill);

	/**
	 * Get the color being drawn.
	 *
	 * @return The color being drawn.
	 */
	Color getColor();

	/**
	 * Set the color being drawn.
	 *
	 * @param color The color being drawn.
	 *
	 * @return True on success, false on failure.
	 */
	bool setColor(Color color);

	/**
	 * Get the brightness of the display.
	 *
	 * @return Display brightness.
	 */
	int getBrightness();

	/**
	 * Set the brightness of the display.
	 *
	 * @param b Display brightness.
	 */
	bool setBrightness(int b);

	/** 
	 * Check whether the draw pipe is valid.
	 *
	 * @return True if the draw pipe is valid, false otherwise.
	 */
	bool isValid();
};

#endif