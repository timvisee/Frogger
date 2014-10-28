#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include "Arduino.h"

class FPSCounter {
private:
	unsigned long start;
	unsigned long dur;
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