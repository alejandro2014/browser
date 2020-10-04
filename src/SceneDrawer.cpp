#include "Font.h"
#include "SceneDrawer.h"

#include <SDL2/SDL.h>

using namespace std;

SceneDrawer::SceneDrawer(SDL_Window *window, SDL_Surface* screenSurface) {
    this->window = window;
    this->screenSurface = screenSurface;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    this->font = new Font("/usr/share/fonts/truetype/msttcorefonts/Courier_New.ttf", 26, (SDL_Color) {200, 0, 0}, (SDL_Color) {50, 50, 50});
}

void SceneDrawer::drawScene() {
    SDL_SetRenderDrawColor(this->renderer, 0x88, 0x88, 0x88, 255);
    SDL_RenderClear(this->renderer);

    this->printString("Titulo", 200, 200);
}

void SceneDrawer::printString(const char *string, int x, int y) {
    SDL_Rect textLocation;
    textLocation.x = x;
    textLocation.y = y;

    SDL_Surface *textSurface = TTF_RenderText_Solid(this->font->getType(), string, this->font->getFgColor());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);

    SDL_RenderCopy(this->renderer, texture, NULL, &textLocation);
    SDL_RenderPresent(this->renderer);

    //SDL_DestroyTexture(texture);
    //SDL_FreeSurface(textSurface);
}
