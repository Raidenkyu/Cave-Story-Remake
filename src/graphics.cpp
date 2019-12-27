#include "graphics.h"
#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Graphics Class
 * Generates the visual content of every frame

*/

Graphics::Graphics() {
  SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0,
                              &this->_window, &this->_renderer);
  SDL_SetWindowTitle(_window, "Cave Story");
}

Graphics::~Graphics() { SDL_DestroyWindow(this->_window); }

SDL_Surface *Graphics::loadImage(const std::string &filepath) {
  if (this->_spriteSheets.count(filepath) == 0)
    this->_spriteSheets[filepath] = IMG_Load(filepath.c_str());
  return this->_spriteSheets[filepath];
}

void Graphics::blitSurface(SDL_Texture *source, SDL_Rect *rect_sourceRectangle,
                           SDL_Rect *rect_destinationRectangle) {
  SDL_RenderCopy(this->_renderer, source, rect_sourceRectangle,
                 rect_destinationRectangle);
}

void Graphics::flip() { SDL_RenderPresent(this->_renderer); }

void Graphics::clear() { SDL_RenderClear(this->_renderer); }

SDL_Renderer *Graphics::getRenderer() const { return this->_renderer; }