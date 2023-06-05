#pragma once

#include <fstream>
#include <vector>
#include <sstream>
#include <type_traits>  // Using: is_same<>

auto read_text_file(std::string const& fname) -> std::vector<std::string>;


