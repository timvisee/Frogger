#include <Arduino.h>
#include "Defaults.h"
#include "Logger.h"
#include "DisplayDriver.h"
#include "HT1632.h"
#include "font_5x4.h"
#include "images.h"

/** Display driver instance. This driver is used to drive the main display. */
DisplayDriver disp = DisplayDriver(PIN_CS, PIN_WRITE, PIN_DATA, PIN_CLOCK);

/**
 * Called once on start
 */
void setup() {
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
	// Draw
	draw();
}

/**
 * Called when a frame should be drawn.
 */
void draw() {
	// Show a status message
	Logger::debug("Screen update!");

	// Clear the screen buffer
	disp.clear(false);
	
	// Draw the demo
	drawDemo();

	// Wait a little before drawing the next frame
	delay(500);
}

void drawDemo() {
	int max = random(2, 10);

	for(int i = 0; i < max; i++) {
		// Draw a random line
		selectRandomColor();
		disp.drawLine(random(0, 16), random(0, 16), random(0, 16), random(0, 16));
		
		// Draw a random rectangle
		selectRandomColor();
		disp.drawRect(16 + random(0, 16), random(0, 16), 16 + random(0, 16), random(0, 16));
		
		// Render the buffered screen
		disp.render();
		delay(100);
	}
}

void selectRandomColor() {
	disp.setColor(static_cast<Color>(random(1, 4)));
}















int i = 0;
int btn = 0;
int frogy = 0;
int frogx = 0;

void start() {
	HT1632.drawImage(IMG_START1, IMG_START1_WIDTH,  IMG_START1_HEIGHT, 0, 0);
}

void startscreen() {
	HT1632.drawImage(IMG_STARTSC, IMG_STARTSC_WIDTH,  IMG_STARTSC_HEIGHT, 0, 0);
}

void lanes() {
	/*HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 6);
	HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 9);
	HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 12);
	HT1632.drawImage(IMG_LANE, IMG_LANE_WIDTH,  IMG_LANE_HEIGHT, 0, 3);*/
	
	disp.setColor(COLOR_RED);
	disp.drawLine(0, 3, 32, 3);
	disp.drawLine(0, 6, 32, 6);
	disp.drawLine(0, 9, 32, 9);
	disp.drawLine(0, 12, 32, 12);
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
