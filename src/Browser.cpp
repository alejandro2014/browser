#include "Browser.h"
#include "Font.h"
#include "SceneDrawer.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

Browser::Browser(Font* font) {
    this->headerFont = font;
    this->window = this->createWindow("Browser v0.0.1", 800, 600);
    this->renderer = this->createRenderer(this->window);
    *this->sceneDrawer = SceneDrawer(this->renderer);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Could not initialize sdl2: " << SDL_GetError() << endl;
        return;
    }

    if (this->window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return;
    }

    this->screenSurface = SDL_GetWindowSurface(this->window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xAA, 0xAA, 0xAA));

    SDL_UpdateWindowSurface(this->window);
}

SDL_Window* Browser::createWindow(const char *title, int width, int height) {
    SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
    }

    return window;
}

SDL_Renderer* Browser::createRenderer(SDL_Window *window) {
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == NULL) {
        printf("Could not create renderer: %s\n", SDL_GetError());
    }

    return renderer;
}

void Browser::loop() {
    SDL_Event event;
    int quit = 0;

    while(!quit) {
        SDL_WaitEvent(&event);

        if(event.type == SDL_QUIT) {
            quit = 1;
        }
    }
}

Browser::~Browser() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
