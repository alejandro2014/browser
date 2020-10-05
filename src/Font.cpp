#include "Font.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

Font::Font(const char *path, int size, SDL_Color fg) {
    this->type = TTF_OpenFont(path, size);

    if(this->type == NULL) {
        cout << "Could not load the font " << path << endl;
        cout << TTF_GetError() << endl;
    }

    this->fgColor = fg;
}

TTF_Font* Font::getType() {
    return this->type;
}

SDL_Color Font::getFgColor() {
    return this->fgColor;
}

Font::~Font() {
    TTF_CloseFont(this->type);
}
