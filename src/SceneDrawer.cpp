#include "Font.h"
#include "SceneDrawer.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

SceneDrawer::SceneDrawer(SDL_Window *window, SDL_Surface* screenSurface) {
    this->window = window;
    this->screenSurface = screenSurface;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    this->font = new Font("/usr/share/fonts/truetype/msttcorefonts/Courier_New.ttf", 16, (SDL_Color) {180, 180, 180}, (SDL_Color) {50, 50, 50});
}

void SceneDrawer::drawScene() {
    //cout << this->screenSurface << endl;
    //this->sceneDrawer->printString(this->headerFont, "Titulo", 100, 100);
    SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0xAA, 0xAA, 0xAA));

    SDL_UpdateWindowSurface(this->window);
}

void SceneDrawer::printString(const char *string, int x, int y) {
    SDL_Surface *textSurface = TTF_RenderText_Shaded(this->font->getType(), string, this->font->getFgColor(), this->font->getBgColor());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_Rect textLocation;
    textLocation.x = x;
    textLocation.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);
    SDL_RenderCopy(this->renderer, texture, NULL, &textLocation);
}
