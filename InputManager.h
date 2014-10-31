/**
 * InputManager.h
 * Header file
 *
 * The input manager provides an easy interface to all input methods.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

/**
 * InputManager class.
 * 
 * @package core
 * @author Tim Visee
 */
class InputManager {
public:
	/**
	 * Initialize.
	 *
	 * @return True on success, false on failure.
	 */
	static bool init();
};

#endif