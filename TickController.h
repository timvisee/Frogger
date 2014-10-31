#ifndef TICKCONTROLLER_H
#define TICKCONTROLLER_H

#include "Arduino.h"
#include "Time.h"

class TickController {
private:
	/** Defines the time the last tick occured */
	float lastTick;
	/** Defines the offset for the upcomming tick */
	float offset;
	/** Defines the desirable ticks per second */
	int tps;
	/**
	 * Defines the tick delta time in seconds.
	 * This value is calculated automatically when the desired TPS is set.
	 */
	float tickDelta;

	/**
	 * Constructor.
	 */
	TickController();

public:
	/**
	 * Constructor.
	 *
	 * @param tps The desirable ticks per second to run at.
	 */
	TickController(int tps);

	/**
	 * Get the desirable ticks per second.
	 *
	 * @return The desirable ticks per second.
	 */
	int getTps();

	/**
	 * Set the desirable ticks per second.
	 *
	 * @param tps The desirable ticks per second.
	 *
	 * @return True on success, false on failure because the value was invalid.
	 */
	bool setTps(int tps);

	/**
	 * Get the delta time in seconds between each tick.
	 * This value is calculated automatically when the desired TPS is set.
	 *
	 * @return The delta time in seconds between each tick.
	 */
	float getTickDelta();
	
	/**
	 * Try to fire a tick. The tick will only be fired successfully if 
	 *
	 * @return True will be returned if a tick was fired, false otherwise.
	 */
	bool tick();

	/**
	 * Get the time in seconds the next tick should be fired at.
	 * If the tick should have been fired already a negative value might be returned.
	 *
	 * @return The tiem in seconds the next tick should be fired at, this value may be negative.
	 */
	float getNextTickIn();

	/**
	 * Get the time in seconds the next tick should be fired at.
	 * If the tick should have been fired already a negative value might be returned.
	 *
	 * @param time The current time in seconds.
	 *
	 * @return The tiem in seconds the next tick should be fired at, this value may be negative.
	 */
	float getNextTickIn(float time);

	/**
	 * Get the time in seconds the last tick occured.
	 * 
	 * @return The time in seconds the last tick occured.
	 */
	float getLastTick();

	/**
	 * Set the time the last tick occured to the current time.
	 */
	void setLastTick();

	/**
	 * Set the time the last tick occured.
	 *
	 * @param lastTick The time the last tick occured.
	 *
	 * @return True on success, false on failure because the value was invalid.
	 */
	bool setLastTick(float lastTick);
};

#endif