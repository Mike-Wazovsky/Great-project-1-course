#ifndef PROJECT_PLOT_CPP
#define PROJECT_PLOT_CPP
// TODO delete iostream, it's only for tests
#include <iostream>
#include <string>
#include <vector>
#include<tuple>
#include "plot.h"

std::string Event::get_story() {
    return s;
}

Event Plot::last() {
    return std::get<0>(events[last_event]);
}

Event Base::give_a_story() {
    int story = rand() % plots.size();
    if (plots[story].last_event != plots[story].events.size()) {
        return plots[story].last();
    }
    return Event("Sorry, our story is ended",0,0, true);
}

void Plot::add_event(const Event& event_, int cons1_, int cons2_) {
    events.emplace_back(std::make_tuple(event_, cons1_, cons2_));
}

void Base::add_plot(Plot plot) {
    plots.push_back(plot);
}

void Base::count_a_conclusion(bool decision) {
    plots[last_plot].count_a_conclusion(decision);
}

void Plot::count_a_conclusion(bool decision) {
    if (decision)
        last_event = std::get<1>(events[last_event]);
    else
        last_event = std::get<2>(events[last_event]);
}
#endif //PROJECT_PLOT_CPP
