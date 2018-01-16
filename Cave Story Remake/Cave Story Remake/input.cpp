#include "input.h"

/* Input Class
 * Checks the state of the keyboard
 */

void Input::beginNewFrame() {
	//At the beginning of every frame, previous pressed or released keys are irrelevant so they are reseted
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//If a key is pressed
void Input::keyDownEvent(const SDL_Event &event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

//If a key is released
void Input::keyUpEvent(const SDL_Event &event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

bool Input::IssKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}