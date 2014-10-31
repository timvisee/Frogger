/**
 * DisplayDriver.h
 * Header file
 *
 * This is a driver to control an SURE (bi-color) LED matrix.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef DISPLAYDRIVER_H
#define DISPLAYDRIVER_H

#include "Logger.h"
#include "Color.h"
#include "HT1632.h"
#include "images.h"

#define DISPLAYDRIVER_BRIGHTNESS_DEF 1

/**
 * DisplayDriver class.
 * 
 * @package core
 * @author Tim Visee
 */
class DisplayDriver {
private:
	/** CS pin used by the display. Must be set when setup() is called. */
	int pinCs;
	/** Write pin used by the display. Must be set when setup() is called. */
	int pinWrite;
	/** Data pin used by the display. Must be set when setup() is called. */
	int pinData;
	/** Clock pin used by the display. Must be set when setup() is called. */
	int pinClock;
	/** Defines whether the display has been set up. */
	bool setupStatus;
	/** Defines the color being drawn on the display. */
	Color color;
	/** The brightness of the display. */
	int brightness;

public:
	/**
	 * Constructor.
	 */
	DisplayDriver();

	/**
	 * Constructor.
	 *
	 * @param pinCs CS pin to use.
	 * @param pinWrite Write pin to use.
	 * @param pinData Data pin to use.
	 * @param pinClock Clock pin to use.
	 */
	DisplayDriver(int pinCs, int pinWrite, int pinData, int pinClock);

private:
	/**
	 * Initialize the display driver class.
	 */
	void init();

public:
	/**
	 * Get the CS pin used by the display.
	 * May return 0 if the pin hasn't been set.
	 *
	 * @return The CS pin used by the display.
	 */
	int getCsPin();

private:
	/**
	 * Set the CS pin used by the display.
	 *
	 * @param CS pin to use.
	 *
	 * @return True if the display didn't need to be destroyed because the pin number didn't changed or the display wasn't set up yet.
	 * False if the display was destroyed because it was set up already.
	 */
	bool setCsPin(int pinCs);

public:
	/**
	 * Get the write pin used by the display.
	 * May return 0 if the pin hasn't been set.
	 *
	 * @return The write pin used by the display.
	 */
	int getWritePin();

private:
	/**
	 * Set the write pin used by the display.
	 *
	 * @param Write pin to use.
	 *
	 * @return True if the display didn't need to be destroyed because the pin number didn't changed or the display wasn't set up yet.
	 * False if the display was destroyed because it was set up already.
	 */
	bool setWritePin(int pinWrite);

public:
	/**
	 * Get the data pin used by the display.
	 * May return 0 if the pin hasn't been set.
	 *
	 * @return The data pin used by the display.
	 */
	int getDataPin();

private:
	/**
	 * Set the data pin used by the display.
	 *
	 * @param Data pin to use.
	 *
	 * @return True if the display didn't need to be destroyed because the pin number didn't changed or the display wasn't set up yet.
	 * False if the display was destroyed because it was set up already.
	 */
	bool setDataPin(int pinData);

public:
	/**
	 * Get the clock pin used by the display.
	 * May return 0 if the pin hasn't been set.
	 *
	 * @return The clock pin used by the display.
	 */
	int getClockPin();

private:
	/**
	 * Set the clock pin used by the display.
	 *
	 * @param Clock pin to use.
	 *
	 * @return True if the display didn't need to be destroyed because the pin number didn't changed or the display wasn't set up yet.
	 * False if the display was destroyed because it was set up already.
	 */
	bool setClockPin(int pinClock);

public:
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
	 */
	void setColor(Color color);

	/**
	 * Set up method. This method needs to be called before the display driver is used in order to set up the display.
	 *
	 * @return True if the display has been set up successfully, false otherwise.
	 */
	bool setup();

	/**
	 * Check whether the display driver has been set up.
	 *
	 * @return True if the display driver has been set up, false otherwise.
	 */
	bool isSetup();

private:
	/**
	 * Set whether the display has been set up.
	 *
	 * @param True if the display has been set up, false otherwise.
	 *
	 * @return True if the set up status changed, false otherwise.
	 */
	bool setSetup(bool setup);

public:
	/**
	 * Destroy the display if it has been set up.
	 *
	 * @return True if the display has been destroyed, or was destroyed already. False otherwise.
	 */
	bool destroy();

	/**
	 * Clear the display. This method immediately renders the blank screen after this method has been called.
	 * 
	 * @return True on success, false on failure.
	 */
	bool clear();

	/**
	 * Clear the display. This method only renders the blank screen if render is set to true.
	 *
	 * @param render True to immediately render the blank screen.
	 *
	 * @return True on success, false on failure.
	 */
	bool clear(bool render);

	/**
	 * Render the bufferend screen.
	 *
	 * @return True on success, false on failure.
	 */
	bool render();

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
	 * Get the brightness of the display.
	 *
	 * @return The brightness of the display
	 */
	int getBrightness();

	/**
	 * Set the brightness of the this display.
	 *
	 * @param b The brightness of the display.
	 * The brightness value must be a number from 1 tot 16.
	 * The value may never be zero.
	 */
	bool setBrightness(int b);

	/**
	 * Check whether the display driver has a valid pin configuration.
	 *
	 * @return True if the display driver set up is valid, false otherwise.
	 */
	bool isValid();

private:
	/**
	 * Check whether a pin value is valid and in-bound.
	 *
	 * @return True if the pin number is valid, false otherwise.
	 */
	bool isValidPin(int pin);
};

#endif
