#include "Font.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

Font::Font(const char *path, int size, SDL_Color fg, SDL_Color bg) {
    this->type = TTF_OpenFont(path, size);

    if(this->type == NULL) {
        cout << "Could not load the font " << path << endl;
        cout << TTF_GetError() << endl;
    }

    this->fgColor = fg;
    this->bgColor = bg;
}

SDL_Texture *getStringTexture(TTF_Font *font, SDL_Renderer *renderer, char *string, SDL_Color fgColor, SDL_Color bgColor) {
    SDL_Surface *textSurface = TTF_RenderText_Shaded(font, string, fgColor, bgColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    return texture;
}

TTF_Font* Font::getType() {
    return this->type;
}

SDL_Color Font::getFgColor() {
    return this->fgColor;
}

SDL_Color Font::getBgColor() {
    return this->bgColor;
}

Font::~Font() {
    TTF_CloseFont(this->type);
}

/*SDL_Texture *printString(Font *font, SDL_Renderer *renderer, char *string, int x, int y) {
    trimLine(string);

    SDL_Texture *texture = getStringTexture(font->type, renderer, string, font->fgColor, font->bgColor);

    SDL_Rect textLocation;
    textLocation.x = x;
    textLocation.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);
    SDL_RenderCopy(renderer, texture, NULL, &textLocation);

    return texture;
}

SDL_Texture *getStringTexture(TTF_Font *font, SDL_Renderer *renderer, char *string, SDL_Color fgColor, SDL_Color bgColor) {
    SDL_Surface *textSurface = TTF_RenderText_Shaded(font, string, fgColor, bgColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    return texture;
}

void trimLine(char *line) {
    int linePos = strlen(line) - 1;

    if(*(line + linePos) == '\n') {
        *(line + linePos) = '\0';
    }
}*/
