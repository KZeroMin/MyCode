#pragma once

#include <fstream>
#include <vector>
#include <sstream>
#include <type_traits>  // Using: is_same<>

auto read_text_file(std::string const& fname) -> std::vector<std::string>;

// input_line에 들어있는 data들의 실제 타입에 맞춰 반환
template<typename T>
auto tokenize_by_space(std::vector<T>& input_lines) -> std::vector<std::vector<T>>
{
    std::vector<std::vector<T>> tokens;

    for (auto line : input_lines)
    {
        std::vector<T> elements;
        std::stringstream ss(line);
        std::string token;

        while (ss >> token)
        {
            if constexpr (std::is_arithmetic_v<T>)  //  constexpr을 사용하여 변수, 함수, 템플릿 등을 정의하면 해당 요소는 컴파일 시간에 평가되고,
            {                                       //  실행 시간에는 더 이상의 계산이 필요하지 않는다.
                T value = std::stod(token);
                elements.push_back(value);
            }
            else elements.push_back(token);   
        }

        tokens.push_back(elements);
    }
    return tokens;
}