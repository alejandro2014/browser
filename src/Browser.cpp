#include "Browser.h"
#include "Font.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

Browser::Browser(Font* font) {
    this->headerFont = font;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Could not initialize sdl2: " << SDL_GetError() << endl;
        return;
    }

    this->window = SDL_CreateWindow("Browser v0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    if (this->window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return;
    }

    SDL_Surface* screenSurface = SDL_GetWindowSurface(this->window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xAA, 0xAA, 0xAA));

    SDL_UpdateWindowSurface(this->window);
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
