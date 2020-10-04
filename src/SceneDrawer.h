#ifndef SCENE_DRAWER_H
#define SCENE_DRAWER_H

#include "Font.h"
#include <SDL2/SDL.h>

class SceneDrawer {
private:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Renderer *renderer;
    Font *font;

public:
    SceneDrawer(SDL_Window *window, SDL_Surface* screenSurface);

    void drawScene();
    void printString(const char *string, int x, int y);
};

#endif
