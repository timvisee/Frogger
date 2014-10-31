#include "TickController.h"

TickController::TickController() {
	// Set the field defaults
	this->setTps(10);
	this->setLastTick();
	this->offset = 0.0f;
}

TickController::TickController(int tps) {
	// Set the desired ticks per second
	this->setTps(tps);
}

int TickController::getTps() {
	return this->tps;
}

bool TickController::setTps(int tps) {
	// Make sure the tps is valid
	if(tps <= 0)
		return false;

	// Set the TPS
	this->tps = tps;

	// Calculate and store the tick delta, return the result
	this->tickDelta = ((float) ( 1.0f / ((float) tps)));
	return true;
}

float TickController::getTickDelta() {
	return this->tickDelta;
}

bool TickController::tick() {
	// Store the current time before doing the heavy calculations
	float time = Time::getTime();

	// Get the time until the next tick and make sure we return false if we shouldn't tick yet
	float nextIn = this->getNextTickIn(time);
	if(nextIn > 0)
		return false;

	// Get the time we're late with this tick, and calculate how many full ticks are skipped
	float late = fabs(nextIn);
	int skipped = floor(late / this->getTickDelta());

	// Show a warning if any ticks are skipped
	if(skipped > 0)
		Logger::warning("Can't keep up, skipped " + String(skipped) + " game ticks!");

	// Calulcate the time the time we were late with the current tick, and make sure the value is positive
	float lateCurrent = late - (skipped * this->getTickDelta());
	if(lateCurrent < 0)
		lateCurrent = 0;

	// Set the offset for the next frame, and set the last tick time. We should tick now, return true
	this->offset = lateCurrent;
	this->setLastTick(time);
	return true;
}

float TickController::getNextTickIn() {
	return this->getNextTickIn(Time::getTime());
}

float TickController::getNextTickIn(float time) {
	return (this->lastTick + this->getTickDelta()) - (time + this->offset);
}

float TickController::getLastTick() {
	return this->lastTick;
}

void TickController::setLastTick() {
	this->setLastTick(Time::getTime());
}

bool TickController::setLastTick(float lastTick) {
	// Make sure the last tick value is valid
	if(lastTick <= 0)
		return false;

	// Set the time the last tick occured, return the result
	this->lastTick = lastTick;
	return true;
}