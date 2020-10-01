#include <SDL2/SDL.h>

class Browser {
    private:
        SDL_Window* window;

    public:
        int init();
        void loop();
        void destroy();
};
