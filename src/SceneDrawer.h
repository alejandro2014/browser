#ifndef SCENE_DRAWER_H
#define SCENE_DRAWER_H

#include <SDL2/SDL.h>

class SceneDrawer {
private:
    SDL_Renderer *renderer;

public:
    SceneDrawer(SDL_Renderer *renderer);

    SDL_Texture* printString(Font *font, const char *string, int x, int y);
    SDL_Texture* getStringTexture(Font *font, SDL_Renderer *renderer, const char *string);
};

#endif
