#include <iostream>
#include <sstream>
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

string to_string(vector<string> v)
{
    string out = "";

    for (string w : v)
    {
        out = out + w + ' ';
    }

    out.pop_back();

    return out;
}

int main()
{   
    string s = "my my name is is kim kim kim young min min this this order may may be broken broken broken";
    const vector<string> origin = convert_string_into_vector(s);
    string out = to_string(get_unique_word(origin));

    assert(out == "be broken is kim may min my name order this young");

    return 0;
}