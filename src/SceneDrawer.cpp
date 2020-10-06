#include "SceneDrawer.h"

using namespace std;

SceneDrawer::SceneDrawer(SDL_Window *window, SDL_Surface* screenSurface) {
    this->window = window;
    this->screenSurface = screenSurface;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    string fontName1 = this->resolveFontName("Courier_New");
    string fontName2 = this->resolveFontName("Courier_New_Bold");

    this->font1 = new Font(fontName1, 26, (SDL_Color) {200, 0, 0});
    this->font2 = new Font(fontName2, 26, (SDL_Color) {200, 0, 0});
    this->font3 = new Font(fontName1, 16, (SDL_Color) {0, 0, 0});
}

void SceneDrawer::drawScene() {
    SDL_Color backgroundColor = (SDL_Color) {0xCC, 0xCC, 0xCC};

    this->clearBackground(&backgroundColor);

    this->printString(this->font1, "Titulo", 200, 200);
    this->printString(this->font2, "Hola que tal", 200, 300);

    this->printString("Any text", this->font3, 0, 400, 15);
}

vector<string> SceneDrawer::getLines(string originalLine) {
    vector<string> textLines;

    textLines.push_back("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor");
    textLines.push_back("incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis");
    textLines.push_back("nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");
    textLines.push_back("Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore");

    return textLines;
}

void SceneDrawer::clearBackground(SDL_Color* backgroundColor) {
    SDL_SetRenderDrawColor(this->renderer, backgroundColor->r, backgroundColor->g, backgroundColor->b, 255);
    SDL_RenderClear(this->renderer);
}

void SceneDrawer::printString(string text, Font *font, int x, int y, int interlinearSpace) {
    vector<string> textLines = this->getLines(text);

    for(int i = 0; i < textLines.size(); i++) {
        this->printString(font, textLines[i], x, y + i * interlinearSpace);
    }
}

void SceneDrawer::printString(Font *font, string text, int x, int y) {
    SDL_Rect textLocation;
    textLocation.x = x;
    textLocation.y = y;

    SDL_Surface *textSurface = TTF_RenderText_Solid(font->getType(), text.c_str(), font->getFgColor());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);

    SDL_QueryTexture(texture, NULL, NULL, &textLocation.w, &textLocation.h);

    SDL_RenderCopy(this->renderer, texture, NULL, &textLocation);
    SDL_RenderPresent(this->renderer);

    //SDL_DestroyTexture(texture);
    //SDL_FreeSurface(textSurface);
}

SceneDrawer::~SceneDrawer() {
    delete this->font1;
    delete this->font2;
    delete this->font3;
}

string SceneDrawer::resolveFontName(string relativeFontName) {
    string fontsBasePath = "/usr/share/fonts/truetype/msttcorefonts/";

    return fontsBasePath + "/" + relativeFontName + ".ttf";
}
