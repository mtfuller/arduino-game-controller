#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <Keyboard.h>

namespace mtfuller_game_controller {
    /**
     * Used to store what control is bound to which key. As well if the control
     * being used by the player.
     */
    struct KeyBinding {
        uint8_t control;
        uint8_t key;
        bool isActive;
    };

    /**
     * The abstract base class for all derived game controller classes.
     */
    class GameController {
        public:
            /**
             * Inits the GameController with MAX_CONTROLS.
             * 
             * \param MAX_CONTROLS The maximum number of key bindings that can be applied to this game controller.
             */
            GameController(const size_t MAX_CONTROLS) {
                Keyboard.begin();
                maxNumberOfKeyBindings = MAX_CONTROLS;
                keyBindings = new KeyBinding[maxNumberOfKeyBindings];
                currentNumberOfKeyBindings = 0;
            }

            ~GameController() {
                delete [] keyBindings;
            }

            /**
             * Adds a key binding to this controller.
             * 
             * \param control The control on the game controller.
             * \param key The key that should be bound to the control.
             */
            void bindControlToKey(const uint8_t control, const uint8_t key);

            /**
             * Poll each control on the controller and sends any appropriate 
             * keyboard events.
             */
            void pollControls();

            /**
             * Returns true if the user is activating a given control. 
             * Otherwise, false.
             * 
             * \param control The control on the game controller.
             */
            virtual bool isControlActive(const uint8_t control) const = 0;

        private:
            // A collection of the key bindings applied to this game controller.
            KeyBinding *keyBindings;

            size_t currentNumberOfKeyBindings;
            size_t maxNumberOfKeyBindings;
    };
}

#endif /* GAME_CONTROLLER_H */