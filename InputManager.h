/**
 * InputManager.h
 * Header file
 *
 * The input manager provides an easy interface to all input methods.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Arduino.h"
#include "Defaults.h"
#include "TinkerKit.h"

/**
 * InputManager class.
 * 
 * @package core
 * @author Tim Visee
 */
class InputManager {
private:
	TKButton btnForward;
	TKButton btnLeft;
	TKButton btnRight;

public:
	/**
	 * Constructor.
	 */
	InputManager();

	/**
	 * Initialize.
	 *
	 * @return True on success, false on failure.
	 */
	bool init();

	/**
	 * Check whether the frogger should move forward
	 *
	 * @return True if the frogger should move forward
	 */
	bool goForward();

	/**
	 * Check whether the frogger should move to the left
	 *
	 * @return True if the frogger should move to the left
	 */
	bool goLeft();

	/**
	 * Check whether the frogger should move to the right
	 * 
	 * @return True if the frogger should move to the right.
	 */
	bool goRight();
};

#endif