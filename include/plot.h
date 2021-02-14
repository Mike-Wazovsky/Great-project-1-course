#ifndef PROJECT_PLOT_H
#define PROJECT_PLOT_H

#include <string>
#include <utility>
#include <vector>

namespace macaftc {
    struct Event {
        std::string s;
        int determination_if_yes;
        int determination_if_no;
        bool is_it_the_end;
        Event(std::string s_, int determination_if_yes_,
              int determination_if_no_, bool is_it_the_end_)
              : s(std::move(s_)),
              determination_if_yes(determination_if_yes_),
              determination_if_no(determination_if_no_),
              is_it_the_end(is_it_the_end_) {
        }
    };
    struct Plot{
	// TODO: check that out
	// Plot(event1, event2, event3)
	// Plot(Event ...events): events(events...) {
	//	
	// }

        std::vector<Event> events;
        size_t cnt = 0;

        Event last() {
            Event e = events[cnt];
            cnt++;
            return e;
        }

        void add_event(Event event) {
            events.push_back(event);
        }

    };
    struct Base{
        std::vector<Plot> plots;
        Event give_a_story();
        void add_plot(Plot plot) {
            plots.push_back(plot);
        }
    };
}

#endif //PROJECT_PLOT_H
