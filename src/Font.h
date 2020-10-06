#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>

using namespace std;

class Font {
private:
    TTF_Font *type;
    SDL_Color fgColor;

public:
    Font(string path, int size, SDL_Color fg);
    ~Font();

    TTF_Font *getType();
    SDL_Color getFgColor();
};

#endif
