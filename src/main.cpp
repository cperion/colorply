#include <iostream>
#include <unordered_map>
#include "commands.hpp"
#if 1
int main ( int argc, char const *argv[] ) {
    std::vector<std::string> args;
    for ( int i = 0; i<argc; i++ ) {
        args.push_back ( std::string ( argv[i] ) );
    }
    int r = cmd ( args );
   return r;
}
#endif
