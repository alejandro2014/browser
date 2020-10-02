#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//#include "global.h"

/*#define FONT_PATH_MAC "/Library/Fonts/Courier New.ttf"
#define FONT_PATH_LINUX "/usr/share/fonts/truetype/msttcorefonts/Courier_New.ttf"
#define FONT_PATH FONT_PATH_LINUX*/

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

    SDL_Texture* printString(Font *font, SDL_Renderer *renderer, char *string, int x, int y);
    //SDL_Texture *printString(Font *font, SDL_Renderer *renderer, char *string, int x, int y);
    //SDL_Texture *getStringTexture(TTF_Font *font, SDL_Renderer *renderer, char *string, SDL_Color fgColor, SDL_Color bgColor);

    //void trimLine(char *line);
};

#endif
