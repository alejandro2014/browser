#ifndef BROWSER_H
#define BROWSER_H

#include "Font.h"
#include "SceneDrawer.h"

#include <SDL2/SDL.h>

class Browser {
    private:
        SDL_Window* window;
        Font* headerFont;
        SDL_Surface* screenSurface;
        SDL_Renderer* renderer;

        SceneDrawer* sceneDrawer;

        SDL_Window* createWindow(const char* title, int width, int height);
        SDL_Renderer* createRenderer(SDL_Window* window);

    public:
        Browser();
        ~Browser();

        void loop();
        void destroy();
};

#endif
