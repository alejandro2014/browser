#include "Browser.h"

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int Browser::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Could not initialize sdl2: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Browser v0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
