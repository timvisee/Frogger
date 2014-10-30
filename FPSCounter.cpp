/**
 * FPSCounter.cpp
 * Source file
 *
 * This FPS counter is an interface to easily count the FPS of any display.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "FPSCounter.h"

FPSCounter::FPSCounter(unsigned long dur) {
	// Reset the counter
	this->reset();
	this->dur = dur;
}

int FPSCounter::count() {
	// Increase the frame count, return the result
	return ++this->frame;
}

void FPSCounter::reset() {
	// Set the variables to it's defaults
	this->start = Time.getMillis();
	this->frame = 0;
}

bool FPSCounter::ready() {
	return (Time.getMillis() >= (this->start + this->dur));
}

int FPSCounter::getFps() {
	// Calculate the duration in time
	unsigned long duration = Time.getMillis() - this->start;

	// Calculate and return the FPS
	return (int) (((float) this->frame) / ((float) duration / 1000));
}