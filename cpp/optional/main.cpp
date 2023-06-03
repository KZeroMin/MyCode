#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

//  map을 사용할 시 어떤 키에 대응하는 값이 빈 문자열이거나, 맵에 키가 존재하지 않는 경우
//  키가 존재하는데 대응하는 값이 빈 문자열일 경우, 제데로 구분하지 못한다.
//  

namespace
{
    auto get_value_form_map(const map<int, string>& m, int key ) -> optional<string>
    {
        auto iter = m.find(key);

        if (iter != m.end())
            return iter->second;
        
        return nullopt; //  <optional>에 정의된 객체로 비어있는 optional을 의미한다.
    }
}

int main()
{
    map<int, string> data = {{1, "Alice"}, {2, "James"}, {3, "Bob"}};
    cout << "Values corresponding to 2 on the map: " << get_value_form_map(data, 2).value() << endl;
    cout << "Does 4 exist on the map?: " << boolalpha << get_value_form_map(data, 4).has_value() << endl;

    return 0;
}