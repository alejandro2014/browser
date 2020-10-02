#include "Browser.h"
#include "Font.h"

#include <iostream>

using namespace std;

int main() {
    TTF_Init();

    Font font = Font("/usr/share/fonts/truetype/msttcorefonts/Courier_New.ttf", 16, (SDL_Color) {180, 180, 180}, (SDL_Color) {50, 50, 50});
    Browser browser = Browser(&font);

    //browser.loop();
    browser.~Browser();

    return 0;
}
