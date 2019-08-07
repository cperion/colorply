#include <unordered_map>
#include "functions.hpp"
#include <iostream>
#include <vector>

int cmd ( std::vector< std::string > args )
{
    std::unordered_map<std::string, int(*)(std::vector<std::string>)> commandmap;
    commandmap[std::string("help")] = help;
    
    if (commandmap.count( args[1])) {
        commandmap[args[1]](args);
    }
    else {
        std::cout<<"Command not found"<<std::endl;
    }
    return 0;
}

