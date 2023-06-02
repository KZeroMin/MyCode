#include "file_util.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

auto read_txt(string const& fname) -> vector<string>
{
    string line;
    ifstream in(fname);
    vector<string> inputs;

    while(!in.fail())
    {
        getline(in, line);
        inputs.push_back(line);
    }

    return inputs;
}