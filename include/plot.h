#pragma once

#include <string>
#include <utility>
#include<tuple>
#include <vector>

struct Event {
    std::string s;
    int determination_if_yes;
    int determination_if_no;
    bool is_it_the_end;
public:
    Event(std::string s_, int determination_if_yes_,
          int determination_if_no_, bool is_it_the_end_)
            : s(std::move(s_)),
              determination_if_yes(determination_if_yes_),
              determination_if_no(determination_if_no_),
              is_it_the_end(is_it_the_end_) {
    }

    std::string get_story();
};

struct Plot {
    std::vector<std::tuple<Event, int, int>> events;
    size_t last_event = 0;
public:
    Event last();
    void add_event(const Event& event_, int cons_of_yes, int cons_of_no);
    void count_a_conclusion(bool decision);
};

struct Base {
private:
    std::vector<Plot> plots;
    size_t last_plot = 0;
public:
    Event give_a_story();
    void add_plot(Plot plot);
    void count_a_conclusion(bool);
};

//INSIDE PLOT:y
// TODO: check that out
// Plot(event1, event2, event3)
// Plot(Event ...events): events(events...) {
//
// }
