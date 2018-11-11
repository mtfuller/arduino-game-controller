#include "JoyStickController.h"

// The delay between game controls polling. 
#define UPDATE_DELAY 50

JoyStickController gameController;

void setup()
{
	// Joystick Control Bindings
	gameController.bindControlToKey(JOYSTICK_FORWARD, KEY_UP_ARROW);
	gameController.bindControlToKey(JOYSTICK_LEFT, KEY_LEFT_ARROW);
	gameController.bindControlToKey(JOYSTICK_BACKWARD, KEY_DOWN_ARROW);
	gameController.bindControlToKey(JOYSTICK_RIGHT, KEY_RIGHT_ARROW);

	// Other Control Bindings
	gameController.bindControlToKey(BUTTON_TOP, 'x');
	gameController.bindControlToKey(BUTTON_LEFT, KEY_RETURN);
	gameController.bindControlToKey(BUTTON_RIGHT, 'c');
	gameController.bindControlToKey(BUTTON_JOYSTICK, KEY_LEFT_SHIFT);
}

void loop()
{
	gameController.pollControls();
    delay(UPDATE_DELAY);
}
