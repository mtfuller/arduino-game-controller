#include "GameController.h"

using namespace mtfuller_game_controller;

void GameController::bindControlToKey(const uint8_t control, const uint8_t key) {
    if (currentNumberOfKeyBindings >= maxNumberOfKeyBindings) 
        return;

    KeyBinding keyBinding = {
        control,
        key,
        false
    };

    keyBindings[currentNumberOfKeyBindings++] = keyBinding;
}

void GameController::pollControls() {
    for (int i = 0; i < currentNumberOfKeyBindings; i++) {
        bool isActive = isControlActive(keyBindings[i].control);

        if (isActive == keyBindings[i].isActive) 
            continue;

        keyBindings[i].isActive = isActive;

        if (keyBindings[i].isActive) {
            Keyboard.press(keyBindings[i].key);
        } else {
            Keyboard.release(keyBindings[i].key);
        }
    }
}