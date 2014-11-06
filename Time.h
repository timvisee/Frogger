/**
 * Time.h
 * Header file
 *
 * This provides an interface to easly handle timings, such as the current time in milliseconds or seconds, or the delta time of a frame.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef TIME_H
#define TIME_H

#include "Arduino.h"

/**
 * Time class.
 * 
 * @package core
 * @author Tim Visee
 */
class Time {
public:
	/**
	 * Get the number of milliseconds passed since the Arduino started.
	 *
	 * @return Number of milliseconds passed since start.
	 */
	unsigned long static getMillis();

	/**
	 * Get the number of milliseconds passed since the Arduino started.
	 * The number returned will be the total amount of milliseconds unless isCurrentSecond is set to true.
	 * If isCurrentSecond is set to true the number of milliseconds passed in the current second will be returned.
	 *
	 * @param inCurrentSecond True to just return the number of passed milliseconds in the current second,
	 * false to return the total number of passed milliseconds.
	 *
	 * @return The number of passed milliseconds.
	 */
	unsigned long static getMillis(bool inCurrentSecond);

	/**
	 * Get the number of seconds passed since the Arduino started.
	 *
	 * @return Number of seconds passed since start.
	 */
	unsigned long static getSeconds();

	/**
	 * Get the number of passed seconds as a float since the Arduino started.
	 *
	 * @return Current time in seconds since start.
	 */
	float static getTime();
};

#endif