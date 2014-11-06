/**
 * Time.cpp
 * Source file
 *
 * This provides an interface to easly handle timings, such as the current time in milliseconds or seconds, or the delta time of a frame.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "Time.h"

unsigned long Time::getMillis() {
	return Time::getMillis(false);
}

unsigned long Time::getMillis(bool inCurrentSecond) {
	if(!inCurrentSecond)
		return millis();
	return millis() % 1000;
}

unsigned long Time::getSeconds() {
	return floor(millis() / 1000);
}

// TODO: Make sure the method bellow is returning proper values!
float Time::getTime() {
	float sec = Time::getSeconds();
	float mil = Time::getMillis(true);
	mil = mil / 1000;
	return sec + mil;
}