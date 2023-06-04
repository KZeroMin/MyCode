#pragma once

#include <string>
#include <vector>

using MemberInfo = std::vector<std::pair<int, std::string>>;

auto sort_by_age(std::vector<std::string>& inputs) -> std::vector<std::pair<int, std::string>>;