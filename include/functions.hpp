#pragma once
#include <vector>
#include <string>


std::vector<std::string> splitstr(std::string const &string, std::string delimiter);

std::string getfname(const char *s);

std::vector<std::string> lsimages(const char *dirpath, std::vector<std::string> exts);