#include "util/file.io.hpp"
#include "util/sort.hpp"

#include<iostream>

int main()
{
    auto lines = read_text_file("../input.txt");
    auto result = sort_by_age(lines);

    for (auto line : result)
        std::cout << line.first << " " << line.second << std::endl;
    /*
    result: 17 Bob
            20 Sunyoung
            21 Junkyu
            21 Dohyun
    */
    return 0;
}