#ifndef SCENE_DRAWER_H
#define SCENE_DRAWER_H

#include "Font.h"

#include <SDL2/SDL.h>
#include <string>

using namespace std;

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

    void clearBackground(SDL_Color* backgroundColor);
    void printString(Font *font, string text, int x, int y);

    string resolveFontName(string relativeFontName);
};

#endif
