#include <Arduino.h>
#include "Defaults.h"
#include "Logger.h"
#include "Time.h"
#include "FPSCounter.h"
#include "TickController.h"
#include "DisplayDriver.h"
#include "DrawPipe.h"
#include "GameController.h"
#include "FroggerGame.h"
#include "HT1632.h"
#include "font_5x4.h"
#include "images.h"

/** Display driver instance. This driver is used to drive the main display. */
DisplayDriver disp = DisplayDriver(PIN_CS, PIN_WRITE, PIN_DATA, PIN_CLOCK);
/** Tick controller, used to precisely control the ticks fired to game. */
TickController tc = TickController(TICK_COUNT);
/** FPS Counter instance */
FPSCounter fps = FPSCounter(FPS_INFO_INTERVAL);
/** Game controller instance */
GameController gc = GameController();

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

	// Starting the frogger game using the game controller
	Logger::debug("Launching frogger game...");
	gc.setGame(FroggerGame());
	Logger::debug("Frogger game launched!");

	// Reset the FPS counter
	fps.reset();
}

/**
 * Called once each loop
 */
void loop () {
	// Do the game logic
	doGameLogic();
}

/**
 * Do a game logic update, this fires update, tick and draw calls to the game.
 */
void doGameLogic() {
	// Update the game
	gc.updateGame();

	// Tick the game
	if(tc.tick())
		gc.tickGame();

	// Draw
	drawGame();
}

/**
 * Called when a frame should be drawn.
 */
void drawGame() {
	// Clear the screen buffer
	disp.clear(false);
	
	// Create a draw pipe to draw on the display and render the game through the game controller
	DrawPipe pipe = DrawPipe(&disp);
	gc.renderGame(&pipe);

	// Render the display
	disp.render();

	// Handle the FPS
	handleFps();
}

/**
 * Handle the FPS counter.
 */
void handleFps() {
	// Count the next FPS frame
	fps.count();
	if(fps.ready()) {
		Logger::info("FPS: " + String(fps.getFps()));
		fps.reset();
	}
}

void selectRandomColor() {
	disp.setColor(static_cast<Color>(random(1, 4)));
}