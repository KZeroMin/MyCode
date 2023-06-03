#include <iostream>
#include <map>

using namespace std;

//  map의 기본구조는 map <key type, value type>이다.
//  map은 key를 기준으로 정렬하며, 오름차순으로 정렬한다.
//  만약 내림차순으로 정렬하고 싶다면, map <int, int, greater> map1과 같이 사용한다.
//  map에서 데이터를 찾을 때는 iterator를 사용하며, 찾지 못했을 경우 iterator는 map.end()를 반환한다.

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
    map<int, string> data = {{1, "Alice"}, {2, "James"}, {3, "Bob"}};

    cout << "The value that matched 2: " << get_value_from_map(data, 2).first << endl;
    cout << "The value that matched 3: " << get_value_from_map(data, 3).first << endl;

    // 인덱스 기반
    for (auto iter = data.begin(); iter != data.end(); iter++)
        cout << iter->second << " ";

    cout << endl;

    //  범위 기반
    for (auto iter : data)
        cout << iter.second << " ";

    return 0;
}