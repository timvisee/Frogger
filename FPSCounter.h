/**
 * FPSCounter.h
 * Header file
 *
 * This FPS counter is an interface to easily count the FPS of any display.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include "Time.h"

/**
 * FPSCounter class.
 * 
 * @package core
 * @author Tim Visee
 */
class FPSCounter {
private:
	/** The time in milliseconds since the first frame was counted. */
	unsigned long start;
	/** The timeframe in millisecconds to count the frames in. */
	unsigned long dur;
	/** The current frame. */
	int frame;

public:
	/**
	 * Constructor.
	 *
	 * @param dur Duration of the FPS to measure.
	 */
	FPSCounter(unsigned long dur);

	/**
	 * Count a new frame.
	 * 
	 * @return The current frame.
	 */
	int count();

	/**
	 * Reset the FPS counter.
	 */
	void reset();

	/**
	 * Check wheather the FPS counter is ready.
	 *
	 * @return True if the FPS counter is ready, false otherwise.
	 */
	bool ready();

	/**
	 * Get the current FPS
	 *
	 * @return Current FPS
	 */
	int getFps();
};

#endif