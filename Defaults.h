/**
 * Defaults.h
 * Header file
 *
 * This file defines some default values, such as the serial baud rate and the pin configuration.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef DEFAULTS_H
#define DEFAULTS_H

#include "TinkerKit.h"

/** The serial baud rate. */
#define SERIAL_BAUD 19200
/** The CS pin used by the display. */
#define PIN_CS 9
/** The write pin used by the display. */
#define PIN_WRITE 10
/** The data pin used by the display. */
#define PIN_DATA 11
/** The clock pin used by the display. */
#define PIN_CLOCK 12
/** Defines the number of desired ticks each second */
#define TICK_COUNT 4
/** Defines the number of milliseconds to show the FPS info. */
#define FPS_INFO_INTERVAL 5000
/** Defines the button used to forward frogger. */
#define BTN_FORWARD = I0;
/** Defines the button used to move the frogger to the left. */
#define BTN_LEFT = I1;
/** Defines the button used to move the frogger to the right. */
#define BTN_RIGHT = I2;

#endif