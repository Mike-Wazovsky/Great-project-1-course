#pragma once

#include "json.hpp"
#include <fstream>
#include <set>
#include <string>

using json = nlohmann::json;

void add_objects(json &j, std::set<std::string> &objects, std::string e);

void translation_from_json_to_uml(json &j, std::string path);