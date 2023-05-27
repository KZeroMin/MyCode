//  문제:
//  정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다
//  이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
//  여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다
//  지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>

using namespace std;

namespace
{
    auto make_map(vector<vector<int>>& map, int _size) -> void
    {
        for (int i = 0; i < _size; i++)
        {
            string str;
            cin >> str;

            for (int j = 0; j < str.length(); j++)
                map[i][j] = str[j] - '0';   // 문자 '0'이 10진법으로 48임을 이용
        }
    }

    auto go(int row, int col, int _size, vector<vector<int>>& map, vector<vector<int>>& visit) -> bool const
    {
        if (row < 0 || row >= _size || col < 0 || col >= _size) return false;
        else if (visit[row][col] == 1 || map[row][col] == 0) return false;
        else return true;

    }

    auto do_dfs(int row, int col, vector<vector<int>>& map, vector<vector<int>>& visit, int& cnt) -> void
    {
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int _size = map.size();

        if (!go(row, col, _size, map, visit)) return;

        visit[row][col] = 1;
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int new_r = row + dr[i];
            int new_c = col + dc[i];
            do_dfs(new_r, new_c, map, visit, cnt);
        }
    }

    auto count_house(vector<vector<int>>& map) -> vector<int>
    {
        int _size = map.size();
        vector<vector<int>> visit(_size, vector<int>(_size, 0));
        vector<int> house_count;

        for (int row = 0; row < _size; row++)
            for (int col = 0; col < _size; col++)
                if (visit[row][col] == 0 && map[row][col] == 1)
                {
                    int cnt = 0;
                    do_dfs(row, col, map, visit, cnt);
                    house_count.push_back(cnt);
                }

        sort(house_count.begin(), house_count.end());

        return house_count;
    }

    template<typename T>
    auto to_s(const vector<T> v) -> string const
    {
        return accumulate(v.begin()
                        , v.end()
                        , ""s
                        , [](const auto& l, const auto& r)
                        {
                            return (l.empty() ? to_string(r) : l + " " + to_string(r));
                        });
    }
}

int main()
{
    /*
    input example: 
    7
    0110100
    0110101
    1110101
    0000111
    0100000
    0111110
    0111000
    */
    int size;
    string result;
    cin >> size;

    vector<vector<int>> map(size, vector<int>(size));
    vector<int> complexes;

    make_map(map, size);
    result = to_s(count_house(map));

    assert(result == "7 8 9");
    
    return 0;
}