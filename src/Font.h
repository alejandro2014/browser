#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Font {
private:
    TTF_Font *type;
    SDL_Color fgColor;
    SDL_Color bgColor;

public:
    Font(char const *path, int size, SDL_Color fg, SDL_Color bg);
    ~Font();

    TTF_Font *getType();
    SDL_Color getFgColor();
    SDL_Color getBgColor();
};

#endif
