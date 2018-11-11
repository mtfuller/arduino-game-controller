# Arduino Game Controller
A small Arduino sketch written for the Arduino Leonardo that allows it to interface as a simple game controller.

## Requirments
### Hardware Components
For this project, I used two components for the game controller:
 - Phantom YoYo Joystick Shield for Arudino - [Amazon](https://www.amazon.com/Phantom-YoYo-Compatible-Joystick-Extended/dp/B00J8BWS3O)
 - Arduino Leonardo - [Arduino Store](https://store.arduino.cc/usa/arduino-leonardo-with-headers)

### Software and Environment
To develop and upload the sketch to the Arduino Leonardo, you must use this repository with VS Code on a Windows machine. Please install the following items:
 - Visual Studio Code
 - VS Code Arduino Extension - [Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino)
  - VS Code C/C++ Extension - [Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
 - Arduino IDE (1.8.7) - [Arduino IDE Download](https://www.arduino.cc/en/Main/Software)

## Getting Started
Here is a quick 
 1. Clone the repository
 2. Open up the folder in VS Code.
 3. Plug in the Arduino Leonardo to your PC.
 4. Open the command pallete (`ctrl + shift + P`) and type in `select`. You should see `Arduino: Select Serial Port` pop up in the menu. Please select it and choose the COM port associated with the Arduino Leonardo.
 5. Next, open the command pallete and type in `Upload`. You should see the `Arduino: Upload` task. Please select it.
 6. The sketch should now begin to compile and upload to the connected Arduino.
 7. After finishing, please unplug the device and plug it into the desired PC/MAC you wish to use it with.

**NOTE FOR MAC USERS:** The Arduino Leonardo can function as a keyboard for MacOS, however, the Keyboard Assistant may ask you to identify the keyboard. If this happens, select "Continue" and when it asks you to press the a button on the new keyboard, press the button on your main keyboard. It should then prompt you to select a default keyboard layout (JP, EU, or US). Please select US. The game controller should be usable at this point. 

## Changing the Key Bindings
Changing the key bindings for the controller is simple. In the `setup()` function of the `main.ino` file, you can call the `bindControlToKey()` function to bind a control (joystick or button) to a particular keyboard key.

There are 9 different controls for the game controller:
 - `JOYSTICK_FORWARD`
 - `JOYSTICK_LEFT`
 - `JOYSTICK_BACKWARD`
 - `JOYSTICK_RIGHT`
 - `BUTTON_TOP`
 - `BUTTON_LEFT`
 - `BUTTON_BOTTOM`
 - `BUTTON_RIGHT`
 - `BUTTON_JOYSTICK` - The joystick itself can be pushed down like a button!

You can map each control to a corresponding key on the keyboard.

If you want to map a control to a particular character key, simply use a literal character:
```c++
// The following binds the top button to the "A" key on the keyboard.
gameController.bindControlToKey(BUTTON_TOP, 'a');
```

If you want to map a control to a special key, such as shift or control, simply use a modifier key definition:
If you want to map a control to a particular letter, simply use a literal character:
```c++
// The following binds the top button to the left ctrl key on the keyboard.
gameController.bindControlToKey(BUTTON_TOP, KEY_LEFT_CTRL);
```
For a full reference of all the modifier keys that are available to you, please take a look at [Keyboard Modifiers](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/).

**WARNING:** Please do not call `bindControlToKey()` more than once using the same control.