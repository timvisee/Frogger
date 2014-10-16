#include <Arduino.h>
#include "Defaults.h"
#include "Logger.h"
#include "DisplayDriver.h"
#include "HT1632.h"
#include "font_5x4.h"
#include "images.h"

/** Display driver instance. This driver is used to drive the main display. */
DisplayDriver disp = DisplayDriver(PIN_CS, PIN_WRITE, PIN_DATA, PIN_CLOCK);

int i = 0;
int btn = 0;
int frogy = 0;
int frogx = 0;

/**
 * Called once on start
 */
void setup () {
	// Start the serial connection
	Serial.begin(SERIAL_BAUD);

	// Initialize the logger
	Logger::init();

	// Initializing, show a status message
	Logger::info("Initializing...");

	// Set up the display driver
	Logger::info("Setting up display driver...");
	disp.setup();
	Logger::info("Display driver set up successfully!");

	// Successfully initialized, show a status message
	Logger::info("Initialized successfully, Cave Johnson here!");
}

/**
 * Called once each loop
 */
void loop () {
	start();
}

void startscreen() {
	HT1632.drawImage(IMG_STARTSC, IMG_STARTSC_WIDTH,  IMG_STARTSC_HEIGHT, 0, 0);
}

void start() {
	Logger::debug("Screen update!");

	HT1632.selectChannel(0);
	HT1632.clear();
	HT1632.drawImage(IMG_START1, IMG_START1_WIDTH,  IMG_START1_HEIGHT, 0, 0);
	HT1632.render();
	delay(2000);
	HT1632.clear();
	HT1632.render();
	delay(100);
}

void lanes() {
	HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 6);
	HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 9);
	HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 12);
	HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 3);
}

void frog() {
	HT1632.drawImage(IMG_FROG, IMG_FROG_WIDTH,  IMG_FROG_HEIGHT, frogx, frogy);
}

void car() {
	HT1632.drawImage(IMG_CAR, IMG_CAR_WIDTH,  IMG_CAR_HEIGHT, 2, 4);
}

void truck() {
	HT1632.drawImage(IMG_TRUCK, IMG_TRUCK_WIDTH,  IMG_TRUCK_HEIGHT, 0, 0);
}
