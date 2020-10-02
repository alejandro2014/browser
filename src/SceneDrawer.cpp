#include "Font.h"
#include "SceneDrawer.h"

using namespace std;

SceneDrawer::SceneDrawer(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

SDL_Texture* SceneDrawer::printString(Font* font, char *string, int x, int y) {
    SDL_Texture *texture = this->getStringTexture(font, renderer, string);

    SDL_Rect textLocation;
    textLocation.x = x;
    textLocation.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);
    SDL_RenderCopy(renderer, texture, NULL, &textLocation);

    return texture;
}

SDL_Texture* SceneDrawer::getStringTexture(Font *font, SDL_Renderer *renderer, char *string) {
    SDL_Surface *textSurface = TTF_RenderText_Shaded(font->getType(), string, font->getFgColor(), font->getBgColor());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    return texture;
}
