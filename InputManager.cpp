/**
 * InputManager.cpp
 * Source file
 *
 * The input manager provides an easy interface to all input methods.
 *
 * @author Tim Visee
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "InputManager.h"

InputManager::InputManager() {
	this->btnForward = TKButton(14);
	this->btnLeft = TKButton(15);
	this->btnRight = TKButton(16);
	this->init();
}

bool InputManager::init() {
	// Initialize the buttons
	this->btnForward = TKButton(I0);
	this->btnLeft = TKButton(I1);
	this->btnRight = TKButton(I2);
	return true;
}

bool InputManager::goForward() {
	return this->btnForward.pressed();
}

bool InputManager::goLeft() {
	return this->btnLeft.pressed() || this->btnLeft.held();
}

bool InputManager::goRight() {
	return this->btnRight.pressed() || this->btnRight.held();
}