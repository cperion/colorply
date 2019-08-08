#include <unordered_map>
#include "functions.hpp"
#include <iostream>
#include <vector>

int cmd ( std::vector< std::string > args )
{
    if (args.size() == 1 ) {
        args.push_back("help");
    }
    std::unordered_map<std::string, int(*)(std::vector<std::string>)> commandmap;
    commandmap[std::string("help")] = help;
    
    if (commandmap.count(args[1])) {
        int r= commandmap[args[1]](args);
        return r;
    }
    else {
        std::cout<<"Command not found"<<std::endl;
        return 1;
    }
}

