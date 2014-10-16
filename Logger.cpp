/**
 * Logger.h
 * Source file
 *
 * This logger provides an easy interface to log to a console.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "Logger.h"

void Logger::init() {
	// Start the serial connection if it hasn't been started already
	if(!Logger::isStarted())
		Serial.begin(SERIAL_BAUD);

	// Print two blank lines
	Serial.println("");
	Serial.println("");
}

bool Logger::isStarted() {
	return (bool) Serial;
}

bool Logger::log(String msg) {
	// Make sure the logger is started
	if(!Logger::isStarted())
		return false;

	// Log the message, return the result
    Serial.println(Logger::getTimeString() + " " + msg);
	return true;
}

bool Logger::info(String msg) {
    return Logger::log("[INFO] " + msg);
}

bool Logger::warning(String msg) {
    return Logger::log("[WARNING] " + msg);
}

bool Logger::error(String msg) {
    return Logger::log("[ERROR] " + msg);
}

bool Logger::debug(String msg) {
    return Logger::log("[DEBUG] " + msg);
}

String Logger::getTimeString() {
    // Get the seconds and milliseconds part of the string
    int totalSec = floor(millis() / 1000);
	int min = floor(totalSec / 60);
    int sec = totalSec % 60;
    int mil = millis() % 1000;
    
    // Build and return the time string with proper formatting
	return Logger::getFormattedNumber(min, 2) + ":" + Logger::getFormattedNumber(sec, 2) + "." + Logger::getFormattedNumber(mil, 3);
}

String Logger::getFormattedNumber(int num, int minLength) {
	// Convert the number into a string
	String numStr = String(num);

	// Calculate the number of missing zero's
	int diff = minLength - numStr.length();

	// Prepend the zero's
	for(int i = 0; i < diff; i++)
		numStr = "0" + numStr;

	// Return the string
	return numStr;
}