#include "util/file.io.hpp"

#include<iostream>

using namespace std;

int main()
{
    auto lines = read_text_file("../input.txt");
    auto data = tokenize_by_space(lines);

    return 0;
}