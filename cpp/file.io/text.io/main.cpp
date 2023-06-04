#include "util/file.io.hpp"
#include <iostream>

int main()
{
    auto lines = read_text_file("../txt.files/mix.txt");
    auto data = tokenize_by_space(lines);

    for (auto element : data)
    {
        for (auto token : element)
            std::cout << token << " ";
        std::cout << std::endl;
    }

    return 0;
}