#include "controller.h"
#include <iostream>

bool Controller::move() {
    std::string s;
    std::cin >> s;
    // return s == "Yes;
    // or 
    // switch (s)
    //     case "Yes": return true;
    //     case "No": return false;
    //     default: throw MyDefinedException();
    if (s[0] == 'y' || s[0] == 'Y') {
        return true;
    }
    else if (s[0] == 'n' || s[0] == 'N') {
        return false;
    }
    // TODO return an error to player if input is incorrect
    return false;
}