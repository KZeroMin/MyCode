#include "file.io.hpp"

using namespace std;

auto read_text_file(string const& fname) -> vector<string>
{
    std::vector<std::string> lines;
    std::ifstream file(fname);
    std::string line;

    if (file.is_open())
    {
        while(getline(file, line))
        {
            lines.push_back(line);
        }
    }
    else throw std::runtime_error("File open fail");

    return lines;
}
