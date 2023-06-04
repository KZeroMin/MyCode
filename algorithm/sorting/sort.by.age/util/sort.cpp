#include "sort.hpp"

#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

auto tokenize_line(string& line) -> pair<int, string>
{
    stringstream ss(line);
    int age;
    string name;

    ss >> age >> name;

    return make_pair(age, name);
}

auto enter_tokenized_info(vector<string>& lines) -> MemberInfo
{
    MemberInfo data;

    for (auto line : lines)
    {
        data.push_back(tokenize_line(line));
    }

    return data;
}

auto compare(const pair<int, string>& a, const pair<int, string>& b) -> bool
{
    if (a.first < b.first) return true;
    return false;
}

auto sort_by_age(vector<string>& lines) -> MemberInfo
{
    auto data = enter_tokenized_info(lines);
    stable_sort(data.begin(), data.end(), compare);

    return data;
}