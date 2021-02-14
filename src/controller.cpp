#include "controller.h"
#include <iostream>

bool macaftc::Controller::Move() {
    std::string s;
    std::cin >> s;
    // return s == "Yes;
    // or 
    // switch (s)
    //     case "Yes": return true;
    //     case "No": return false;
    //     default: throw MyDefinedException();
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
