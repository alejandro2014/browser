#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font {
private:
    TTF_Font *type;
    SDL_Color fgColor;

public:
    Font(char const *path, int size, SDL_Color fg);
    ~Font();

    TTF_Font *getType();
    SDL_Color getFgColor();
};

#endif
