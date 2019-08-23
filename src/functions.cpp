#pragma once
#include <iostream>
#include "functions.hpp"
#include <fstream>
#include <filesystem>
#include <algorithm>


void print(const char* str) {
    std::cout << str << std::endl;
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

std::string getfname(const char * s) {
    std::string sstr(s);
    char sep = '/';

#ifdef _WIN32
    sep = '\\';
#endif

    size_t i = sstr.rfind(sep, sstr.length());
    if (i != std::string::npos)
    {
        return (sstr.substr(i + 1, sstr.length() - i));
    }

    return sstr;
}

std::vector<std::string> lsimages(const char *dirpath, std::vector<std::string> exts) {
    std::vector<std::string> out;
    for (auto const &entry : std::filesystem::directory_iterator(dirpath)) {
        std::string fpath = entry.path().string();
        std::string fext = entry.path().extension().string();
        if (std::find(exts.begin(), exts.end(), fext) != exts.end() & entry.is_regular_file()){
            out.push_back(fpath);
        }
    }
    return out;
}

#if 0
int main(int argc, char ** argv) {
    std::vector<std::string> exts{".TIF", ".JPG", ".JPEG", ".tiff", ".jpg"};
    auto ls = lsimages(argv[1], exts);
    std::cout << ls[1] << std::endl;
}
#endif