#include "controller.h"
#include <iostream>

bool macaftc::Controller::Move() {
    std::string s;
    std::cin >> s;
    if (s == "Yes") {
        return true;
    }
    else {
        if (s == "No") {
            return false;
        }
    }
    return false;
}