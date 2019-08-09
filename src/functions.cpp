#include <iostream>
#include "functions.hpp"
#include <fstream>


void print(const char* str) {
    std::cout << str << std::endl;
}

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
        print("Unable to open helpfile");
        return 1; 
    }
    return 0;
}

std::vector<std::string> splitstr(std::string const &string, std::string delimiter) {
    std::string token= "";
    std::vector<std::string> out;
    int start = 0;
    int end = string.find(delimiter);
    int l = delimiter.length();
    while (end != std::string::npos) {
        token = string.substr(start, end-start);
        out.push_back(token);
        start = end + l;
        end = string.find(delimiter,start);
    }
    token = string.substr(start);
    out.push_back(token);
    return out;
}
