/**
 * Logger.h
 * Header file
 *
 * This logger provides an easy interface to log to a console.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include "Time.h"
#include "Defaults.h"

/**
 * Logger class. Used for basic logging.
 *
 * @package core
 * @author Tim Visee
 */
class Logger {
public:
    /**
     * Initialize the logger. This is required before logging may be used.
     */
    static void init();

	/**
	 * Check whether the logger is initialized and started successfully.
	 *
	 * @return True if the logger is started successfully, false otherwise.
	 */
	static bool isStarted();
    
private:
    /**
     * Log a message.
     *
     * @param msg The message to log.
	 *
	 * @return True on success, false on failure if the logger wasn't started properly.
     */
    static bool log(String msg);

public:
    /**
     * Log an info message.
     *
     * @param msg The info message to log.
	 *
	 * @return True on success, false on failure if the logger wasn't started properly.
     */
    static bool info(String msg);
    
    /**
     * Log a warning message.
     *
     * @param msg The warning message to log.
	 *
	 * @return True on success, false on failure if the logger wasn't started properly.
     */
    static bool warning(String msg);
    
    /**
     * Log an error message.
     *
     * @param msg The error message to log.
	 *
	 * @return True on success, false on failure if the logger wasn't started properly.
     */
    static bool error(String msg);
    
    /**
     * Log a debug message.
     *
     * @param msg The debug message to log.
	 *
	 * @return True on success, false on failure if the logger wasn't started properly.
     */
    static bool debug(String msg);
    
private:
    /**
     * Get the current time as a string with proper formatting.
     *
     * @return The current time as a string.
     */
    static String getTimeString();

	/**
	 * Get a number as a string with proper formatting.
	 * The number will be prefixed with zero's if the minLength requirement isn't met.
	 *
	 * @param num The number to get as a string.
	 * @param minLength The minimum length of the number.
	 *
	 * @return Formatted number.
	 */
	static String getFormattedNumber(int num, int length);
};

#endif
