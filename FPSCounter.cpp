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
	this->start = millis();
	this->frame = 0;
}

bool FPSCounter::ready() {
	return (millis() >= (this->start + this->dur));
}

int FPSCounter::getFps() {
	// Calculate the duration in time
	unsigned long duration = millis() - this->start;

	// Calculate and return the FPS
	return (int) (((float) this->frame) / ((float) duration / 1000));
}