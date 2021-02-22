#include "story.h"

Base first_myth() {
    Plot plot;
    Base base;
    std::vector<std::string> story;
    std::vector<Event> events;
    std::string line;
    int cnt = 0;
    std::ifstream in1(R"(C:\Users\Michael\Desktop\Great-project-1-course\TESTS\First_myth.txt)");
    while (getline(in1, line)) {
        story.push_back(line);
        cnt++;
    }
    in1.close();
    std::ifstream in2(R"(C:\Users\Michael\Desktop\Great-project-1-course\TESTS\First_myth_resources.txt)");
    for (int i = 0; i < cnt; i++) {
        int det_yes, det_no, is_end;
        in2 >> det_yes >> det_no >> is_end;
        events.push_back({story[i], det_yes, det_no, bool(is_end)});
    }
    in2.close();
    std::ifstream in3(R"(C:\Users\Michael\Desktop\Great-project-1-course\TESTS\First_myth_references.txt)");
    for (int i = 0; i < cnt; i++) {
        int ref_yes, ref_no;
        in3 >> ref_yes >> ref_no;
        plot.add_event(events[i], ref_yes, ref_no);
    }
    in3.close();
    base.add_plot(plot);
    return base;
}