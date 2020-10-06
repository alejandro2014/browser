#include "Browser.h"

using namespace std;

Browser::Browser() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Could not initialize sdl2: " << SDL_GetError() << endl;
        return;
    }

    TTF_Init();

    this->window = this->createWindow("Browser v0.0.1", 800, 600);
    this->sceneDrawer = new SceneDrawer(this->window, this->screenSurface);
}

SDL_Window* Browser::createWindow(const char *title, int width, int height) {
    SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
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

        this->sceneDrawer->drawScene();
    }
}

Browser::~Browser() {
    SDL_DestroyWindow(this->window);
    TTF_Quit();
    SDL_Quit();
}
