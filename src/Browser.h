#ifndef BROWSER_H
#define BROWSER_H

#include "Font.h"

#include <SDL2/SDL.h>

class Browser {
    private:
        SDL_Window* window;
        Font* headerFont;

    public:
        Browser(Font* font);
        ~Browser();

        void loop();
        void destroy();
};

#endif
