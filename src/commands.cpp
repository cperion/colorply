#include <unordered_map>
#include "functions.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include "processing.hpp"
#include "ioply.hpp"
#include "ioimage.hpp"
#include "ioxml.hpp"

int help(std::vector<std::string> args) { // Dispaly the help file
    
    std::string path("doc/");
    if (args.size() < 3) {
        path=std::string("doc/helpfile");
    }
    else {
        path.append(args[2]);
        path=std::string("doc/").append(args[2]);
    }
    std::ifstream file(path);
    if (file) {
        std::string line;
        std::cout<<std::endl;
        while(!file.eof()) {
            getline(file, line);
            std::cout<<line<<std::endl;
        }
        std::cout<<std::endl;
    }
    else{
        std::cout << "Unable to open helpfile" << std::endl;
        return 1;
    }
    return 0;
}

int add(std::vector<std::string> args) {
    if (args.size() < 8) {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }
    auto inputfile=args[2];
    auto outputfile=args[3];
    auto imgdir=args[4];
    auto oridir=args[5];
    auto calibfile=args[6];
    auto name=args[7];

    Camera cam(calibfile.c_str());
    auto pointv = readply(inputfile.c_str());
    auto imgv = load_images(imgdir.c_str(), oridir.c_str(), &cam);
    auto outv = projv(pointv, imgv);
    happly::PLYData ply(inputfile);
    ply.getElement("vertex").addProperty(name, outv);
    ply.write(outputfile);
    return 0;
}

int cmd ( std::vector< std::string > args )
{
    if (args.size() == 1 ) {
        args.push_back("help");
    }
    std::unordered_map<std::string, int(*)(std::vector<std::string>)> commandmap;

    commandmap[std::string("help")] = help;
    commandmap[std::string("add")] = add;

    if (commandmap.count(args[1])) {
        int r= commandmap[args[1]](args);
        return r;
    }
    else {
        std::cout<<"Command not found"<<std::endl; return 1;
    }
}
