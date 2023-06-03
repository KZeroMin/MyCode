#include <iostream>
#include <map>

using namespace std;

namespace
{
    auto get_value_from_map(const map<int, string>& m, int key) -> pair<string, bool>
    {
        auto itr = m.find(key);

        if (itr != m.end())
            return make_pair(itr -> second, true);

        return make_pair(string(), false);
    }
}

int main()
{
    map<int, string> data = {{1, "HELLO"}, {2, "NICE"}, {3, "GOOD"}};

    cout << "The value that matched 2: " << get_value_from_map(data, 2).first << endl;
    cout << "The value that matched 3: " << get_value_from_map(data, 3).first << endl;
}