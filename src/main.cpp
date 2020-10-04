#include "Browser.h"
#include "Font.h"

#include <iostream>

using namespace std;

int main() {
    Browser browser = Browser();

    browser.loop();
    browser.~Browser();

    return 0;
}
