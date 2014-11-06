/**
 * Viewport.cpp
 * Source file
 *
 * This class represents a viewport.
 *
 * @author Tim Visee; Ben van de Hoeven; Hol Yuen Chung; Peiyi Phung
 * @website http://timvisee.com/
 * @copyright Copyright (c) Tim Visee 2014. All rights reserved.
 */

#include "Viewport.h"

Viewport::Viewport() {
	// Set the field defaults
	this->view.setX(0);
	this->view.setY(0);
	this->view.setWidth(0);
	this->view.setHeight(0);
}

Viewport::Viewport(int w, int h) {
	this->view.setWidth(w);
	this->view.setHeight(h);
}

Viewport::Viewport(Point size) {
	this->view.setSize(size);
}

Viewport::Viewport(Rect view) {
	this->view = view;
}

Viewport::Viewport(int x, int y, int w, int h) {
	this->view.setX(x);
	this->view.setY(y);
	this->view.setWidth(w);
	this->view.setHeight(h);
}

Viewport::Viewport(Point pos, Point size) {
	this->view.setPosition(pos);
	this->view.setSize(size);
}

Rect Viewport::getView() {
	return this->view;
}

Point Viewport::getPosition() {
	return this->view.getPosition();
}

void Viewport::setPosition(Point pos) {
	this->view.setPosition(pos);
}

int Viewport::getX() {
	return this->view.getX();
}

void Viewport::setX(int x) {
	this->view.setX(x);
}

int Viewport::getY() {
	return this->view.getY();
}

void Viewport::setY(int y) {
	this->view.setY(y);
}

Point Viewport::getSize() {
	return this->view.getSize();
}

void Viewport::setSize(Point size) {
	this->view.setSize(size);
}

int Viewport::getWidth() {
	return this->view.getWidth();
}

void Viewport::setWidth(int w) {
	this->view.setWidth(w);
}

int Viewport::getHeight() {
	return this->view.getHeight();
}

void Viewport::setHeight(int h) {
	this->view.setHeight(h);
}