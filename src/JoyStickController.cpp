#include "JoyStickController.h"

bool JoyStickController::isButtonPressed(const uint8_t button) const {
    return !digitalRead(button);
}

int JoyStickController::getJoyStickX() const { 
    return analogRead(JOYSTICK_X); 
}

int JoyStickController::getJoyStickY() const { 
    return analogRead(JOYSTICK_Y);
}

bool JoyStickController::isControlActive(const uint8_t control) const {
    bool isActive = false;

    switch (control) {
        case JOYSTICK_FORWARD:
            isActive = getJoyStickY() > MAX_JOYSTICK_THRESHOLD;
            break;
        case JOYSTICK_LEFT:
            isActive = getJoyStickX() > MAX_JOYSTICK_THRESHOLD;
            break;
        case JOYSTICK_BACKWARD:
            isActive = getJoyStickY() < MIN_JOYSTICK_THRESHOLD;
            break;
        case JOYSTICK_RIGHT:
            isActive = getJoyStickX() < MIN_JOYSTICK_THRESHOLD;
            break;
        case BUTTON_TOP:
            isActive = isButtonPressed(TOP_BUTTON_PIN);
            break;
        case BUTTON_LEFT:
            isActive = isButtonPressed(LEFT_BUTTON_PIN);
            break;
        case BUTTON_BOTTOM:
            isActive = isButtonPressed(BOTTOM_BUTTON_PIN);
            break;
        case BUTTON_RIGHT:
            isActive = isButtonPressed(RIGHT_BUTTON_PIN);
            break;
        case BUTTON_JOYSTICK:
            isActive = isButtonPressed(JOYSTICK_BUTTON_PIN);
            break;
    }

    return isActive;
}