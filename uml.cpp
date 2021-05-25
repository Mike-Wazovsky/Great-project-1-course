#include "uml.h"

void add_objects(json & j, std::set<std::string> & objects, std::string e) {
    objects.insert(e);
    if (j["events"][e]["is_end"] == false) {
        add_objects(j, objects, j["events"][e]["routes"]["yes"]["next_event"]);
        add_objects(j, objects, j["events"][e]["routes"]["no"]["next_event"]);
    }
}

void translation_from_json_to_uml(json & j, std::string path) {
    std::ofstream fout(path);
    fout << "@startuml\n\n";
    std::set<std::string> objects;

    fout << "object " << std::string(j["plot_title"]) << '\n';

    add_objects(j, objects, "event1");
    for (std::string e : objects) {
        fout << "object " << e << '\n';
    }
    fout << '\n';

    fout << "map " << std::string(j["plot_title"]) << " {\n";
    fout << std::string(j["declaring_character"]) << "\n}\n\n";

    for (std::string e : objects) {
        fout << "map " << e << " {\n";
        fout << std::string(j["events"][e]["text"]) << "\n}\n\n";
    }

    fout << std::string(j["plot_title"]) << " --> event1 \n";

    for (std::string e : objects) {
        if (j["events"][e]["is_end"] == false) {
            fout << e << " --> \"yes\" " << std::string(j["events"][e]["routes"]["yes"]["next_event"]) << '\n';
            fout << e << " --> \"no\" " << std::string(j["events"][e]["routes"]["no"]["next_event"]) << '\n';
        }
    }

    fout << "\n@enduml";

    fout.close();
}
