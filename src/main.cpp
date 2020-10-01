#include "Browser.h"

#include <iostream>

using namespace std;

int main() {
    Browser browser;

    browser.init();
    browser.loop();
    browser.destroy();

    return 0;
}
