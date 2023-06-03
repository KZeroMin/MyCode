#include <iostream>
#include <algorithm>
#include <vector>   // utility 헤더파일 포함
#include <optional>


//  Remain works:
//  Have to make hpp, cpp file!!
//  Make input file


using namespace std;

using MemberList = vector<pair<optional<int>, optional<string>>>;
using UserInfo = pair<optional<int>, optional<string>>;

auto get_member_info(const int member_size) -> MemberList
{
    int age;
    string name;
    MemberList member_list;

    for (int i = 0; i < member_size; i++)
    {
        cin >> age >> name;
        member_list.push_back(make_pair(age, name));
    }

    return member_list;
}

auto compare(const UserInfo& a, const UserInfo& b) -> bool
{
    if (a.first && b.first)
        if (a.first.value() < b.first.value()) return true;
        else return false;
    else if (a.first && !b.first) return true;
    else if (!a.first && b.first) return false;
    
    return false;
}

auto sort_member_list(MemberList& member_list) -> void
{
    sort(member_list.begin(), member_list.end(), compare);
}

int main() {
    int member_size, age;
    string name;

    cin >> member_size;

    auto member_list = get_member_info(member_size);
    sort_member_list(member_list);

    for(auto element : member_list)
        cout << element.first.value() << " " << element.second.value() << endl;

    return 0;
}
