#pragma once
#include <vector>
#include <string>

int help(std::vector<std::string>);

std::vector<std::string> splitstr(std::string const &string, std::string delimiter);

std::string getfname(const char *s);

std::vector<std::string> lsimages(char *dirpath, std::vector<std::string> exts);