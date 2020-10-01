#include "Browser.h"

#include <iostream>

using namespace std;

int main() {
    Browser browser;

    browser.setValue(1);
    cout << "Value: " << browser.getValue() << endl;

    return 0;
}
