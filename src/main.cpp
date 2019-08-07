#include <iostream>
#include <unordered_map>
#include "commands.hpp"

int main(int argc, char const *argv[]) {
	std::vector<std::string> args;
	for (int i = 0; i<argc; i++) {
		args.push_back(std::string(argv[i]));
	}
	cmd(args);
	return 0;
}
