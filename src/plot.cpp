#ifndef PROJECT_PLOT_CPP
#define PROJECT_PLOT_CPP
#include <string>
#include <vector>
#include "plot.h"

namespace macaftc {

    Event Base::give_a_story() {
        int story = rand() % plots.size();
        if (plots[story].cnt != plots[story].events.size()) {
            return plots[story].last();
        }
        else {
            return Event("Sorry, our story is ended",0,0, true);
        }
        //int story = 0;
        //return plots[story].last();
    }
}

#endif //PROJECT_PLOT_CPP