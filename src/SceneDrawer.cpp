#include "Font.h"
#include "SceneDrawer.h"

#include <SDL2/SDL.h>

using namespace std;

SceneDrawer::SceneDrawer(SDL_Window *window, SDL_Surface* screenSurface) {
    string *fontsBasePath = "/usr/share/fonts/truetype/msttcorefonts/";

    this->window = window;
    this->screenSurface = screenSurface;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    string fontName1("/Courier_New.ttf");
    string fontName2("/Courier_New_Bold.ttf");

    this->font1 = new Font(fontsBasePath + fontName1, 26, (SDL_Color) {200, 0, 0});
    this->font2 = new Font(fontsBasePath + fontName2, 26, (SDL_Color) {200, 0, 0});
}

void SceneDrawer::drawScene() {
    SDL_SetRenderDrawColor(this->renderer, 0x88, 0x88, 0x88, 255);
    SDL_RenderClear(this->renderer);

    this->printString(this->font1, "Titulo", 200, 200);
    this->printString(this->font2, "Hola que tal", 200, 300);
}

void SceneDrawer::printString(Font *font, const char *string, int x, int y) {
    SDL_Rect textLocation;
    textLocation.x = x;
    textLocation.y = y;

    SDL_Surface *textSurface = TTF_RenderText_Solid(font->getType(), string, font->getFgColor());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);

    SDL_RenderCopy(this->renderer, texture, NULL, &textLocation);
    SDL_RenderPresent(this->renderer);

    //SDL_DestroyTexture(texture);
    //SDL_FreeSurface(textSurface);
}

SceneDrawer::~SceneDrawer() {
    delete this->font1;
    delete this->font2;
}
