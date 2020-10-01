#include <iostream>

using namespace std;

class Browser {
    int value;

    public:
        int getValue();
        void setValue(int value);
};

int Browser::getValue() {
    return value;
}

void Browser::setValue(int val) {
    value = val;
}

int main() {
    Browser browser;

    browser.setValue(1);
    cout << "Value: " << browser.getValue() << endl;

    return 0;
}
