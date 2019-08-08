#include "happly.h"
#include "pugixml.hpp"
#include <iostream>
#include <vector>
#include <string>


int main(int argc, char const *argv[]) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("test/camtest.xml");
    std::cout << result.description() << std::endl;
    pugi::xml_node node = doc.select_node("/ExportAPERO/CalibrationInternConique/CalibDistortion/ModRad/CDist").node();
    std::cout << node.text() << std::endl;
    
    return 0;
}
