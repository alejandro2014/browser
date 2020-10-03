#ifndef SCENE_DRAWER_H
#define SCENE_DRAWER_H

#include <SDL2/SDL.h>

class SceneDrawer {
private:
    SDL_Renderer *renderer;

public:
    SceneDrawer(SDL_Renderer *renderer);

    void drawScene();
    void printString(Font *font, const char *string, int x, int y);
};

#endif
