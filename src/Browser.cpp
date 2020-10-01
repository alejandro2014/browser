#include "Browser.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int Browser::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Could not initialize sdl2: " << SDL_GetError() << endl;
        return 1;
    }

    this->window = SDL_CreateWindow("Browser v0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    if (this->window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Surface* screenSurface = SDL_GetWindowSurface(this->window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xAA, 0xAA, 0xAA));

    SDL_UpdateWindowSurface(this->window);

    return 0;
}

void Browser::loop() {
    SDL_Event event;
    int quit = 0;

    while(!quit) {
        SDL_WaitEvent(&event);

        if(event.type == SDL_QUIT) {
            quit = 1;
        }

        //SDL_Delay(2000);
    }
}

void Browser::destroy() {
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
