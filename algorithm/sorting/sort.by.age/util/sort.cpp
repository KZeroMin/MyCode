#include "sort.hpp"
#include "util.hpp"

#include <algorithm>

using namespace std;

auto sort_by_age(vector<string>& lines) -> MemberInfo
{
    auto data = enter_tokenized_info(lines);
    stable_sort(data.begin(), data.end(), compare);

    return data;
}