#pragma once

#include <iostream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

vector<string> convert_string_into_vector(string input)
{
    vector<string> string_vector;
    stringstream ss(input);
    string str;

    while(getline(ss, str, ' '))
    {
        string_vector.push_back(str);
    }

    return string_vector;
    
}

vector<string> get_unique_word(vector<string> v) 
{
    vector<string> string_vector;
    string previous_word = "";

    sort(v.begin(), v.end());

    for(string w : v)
    {
        if (previous_word == w) continue;
        else
        {
            previous_word = w;
            string_vector.push_back(w);
        }
    }

    return string_vector;
}

template<typename T>
auto join(const vector<T>& v) -> string
{
    return accumulate(v.begin(),
                      v.end(),
                      ""s,
                      [](const auto& l, const auto& r)
                      {
                          return l.empty() ? r : l + " " + r;   //  Lambda expression: ([](const auto& l, const auto& r) { ... }) ->  Specify how the accumulate function combines elements
                      });
}