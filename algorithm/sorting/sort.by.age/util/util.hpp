#pragma once

#include <string>
#include <vector>

using MemberInfo = std::vector<std::pair<int, std::string>>;

auto tokenize_line(std::string& line) -> std::pair<int, std::string>;

auto enter_tokenized_info(std::vector<std::string>& lines) -> MemberInfo;

auto compare(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) -> bool;