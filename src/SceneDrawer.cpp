#include "Font.h"
#include "SceneDrawer.h"

using namespace std;

SceneDrawer::SceneDrawer(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

void SceneDrawer::drawScene() {

}

void SceneDrawer::printString(Font* font, const char *string, int x, int y) {
    SDL_Surface *textSurface = TTF_RenderText_Shaded(font->getType(), string, font->getFgColor(), font->getBgColor());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_Rect textLocation;
    textLocation.x = x;
    textLocation.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);
    SDL_RenderCopy(renderer, texture, NULL, &textLocation);
}
