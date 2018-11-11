#ifndef JOYSTICK_CONTROLLER_h
#define JOYSTICK_CONTROLLER_h

#include <Arduino.h>
#include "GameController.h"

// The button pin values on the Phantom YoYo shield.
#define TOP_BUTTON_PIN 2
#define LEFT_BUTTON_PIN 3
#define BOTTOM_BUTTON_PIN 4
#define RIGHT_BUTTON_PIN 5
#define JOYSTICK_BUTTON_PIN 6

// The analog pin values for the joystick on the Phantom YoYo shield.
#define JOYSTICK_X A0
#define JOYSTICK_Y A1

/**
 * These are used to determine if the joystick is being pushed in a particular 
 * direction.
 */
#define MAX_JOYSTICK_THRESHOLD 750
#define MIN_JOYSTICK_THRESHOLD 350

/**
 * The controls available on the game controller to bind.
 */
#define MAX_CONTROLS 9
enum JoyStickShieldControl {
    JOYSTICK_FORWARD,
    JOYSTICK_LEFT,
    JOYSTICK_BACKWARD,
    JOYSTICK_RIGHT,
    BUTTON_TOP,
    BUTTON_LEFT,
    BUTTON_BOTTOM,
    BUTTON_RIGHT,
    BUTTON_JOYSTICK
};

/**
 * The implemented GameController derived class for the Phantom YoYo joystick 
 * shield for the Arduino.
 */
class JoyStickController : public mtfuller_game_controller::GameController {
    public:
        JoyStickController() : GameController(MAX_CONTROLS) {
            pinMode(TOP_BUTTON_PIN, INPUT);
            pinMode(LEFT_BUTTON_PIN, INPUT);
            pinMode(BOTTOM_BUTTON_PIN, INPUT);
            pinMode(RIGHT_BUTTON_PIN, INPUT);
            pinMode(JOYSTICK_BUTTON_PIN, INPUT);
        };

        ~JoyStickController() {};

        /**
         * Returns true if the given button is being pressed on the Arduino 
         * shield. Otherwise, false.
         * 
         * \param button The pin associated with the desired button.
         */
        bool isButtonPressed(const uint8_t button) const;

        /**
         * Returns an analog value (0-1023) of the X-axis position of the joystick.
         */
        int getJoyStickX() const;

        /**
         * Returns an analog value (0-1023) of the Y-axis position of the joystick.
         */
        int getJoyStickY() const;

        /**
         * Returns true if the control is being activated by the user.
         * 
         * \param control The JoyStickShieldControl value of the control on the
         *      game controller.
         */
        bool isControlActive(const uint8_t control) const;
};

#endif /* JOYSTICK_CONTROLLER_h */
