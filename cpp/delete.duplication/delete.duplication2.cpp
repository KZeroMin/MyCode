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
                          return l.empty() ? r : l + " " + r;   //  람다 표현식([](const auto& l, const auto& r) { ... }): 이항 연산 정의 ->  accumulate 함수가 요소들을 결합하는 방법을 지정
                      });
}


int main()
{   
    string s = "my my name is is kim kim kim young min min this this order may may be broken broken broken";
    const vector<string> origin = convert_string_into_vector(s);
    string out = join(get_unique_word(origin));
    cout << out << endl;
    
    assert(out == "be broken is kim may min my name order this young");

    return 0;
}