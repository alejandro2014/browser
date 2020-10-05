#ifndef SCENE_DRAWER_H
#define SCENE_DRAWER_H

#include "Font.h"

#include <SDL2/SDL.h>
#include <string>

class SceneDrawer {
private:
    SDL_Window* window;
    SDL_Surface* screenSurface;
    SDL_Renderer *renderer;
    Font *font1, *font2;

public:
    SceneDrawer(SDL_Window *window, SDL_Surface* screenSurface);
    ~SceneDrawer();

    void drawScene();
    void printString(Font *font, std::string *text, int x, int y);
};

#endif
