#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"
#include <algorithm>

/* Game Class
 * The "main" class where the principal loop runs, 
 * This loop is where the other classes arr running
 */

namespace {
	//Limit of FPS
	const int FPS = 50;
	const int MAX_FRAME =  5* 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	//Setting up data before begining the loop/game
	Graphics graphics;
	Input input;
	SDL_Event event;
	this->_player = Player(graphics, 100,100);
	int LAST_TIME_UPDATE = SDL_GetTicks();
	//Start Game Loop
	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0)
					input.keyDownEvent(event);
			}
			else if(event.type == SDL_KEYUP){
				input.keyUpEvent(event);
			}

			else if (event.type == SDL_QUIT)
				return;
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
			return;
		}
		else if (input.IssKeyHeld(SDL_SCANCODE_LEFT)) {
			this->_player.moveLeft();
		}
		else if (input.IssKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.moveRight();
		}

		if (!input.IssKeyHeld(SDL_SCANCODE_LEFT) && !input.IssKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELSAPSED_TIME_MS = CURRENT_TIME_MS - LAST_TIME_UPDATE;
		this->update(std::min(ELSAPSED_TIME_MS, MAX_FRAME));
		LAST_TIME_UPDATE = CURRENT_TIME_MS;
		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics) {
	graphics.clear();
	this->_player.draw(graphics);
	graphics.flip();
}

void Game::update(float elapsedTime) {
	this->_player.update(elapsedTime);
}