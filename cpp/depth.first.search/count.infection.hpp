#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;
using Map = vector<vector<int>>;

auto read_file() -> vector<string>
{   
    vector<string> inputs;
    string input;
    ifstream in("input.txt");
    
    while(!in.fail())
    {
        getline(in, input);
        inputs.push_back(input);
    }

    return inputs;
}

auto separate_int_inputs(vector<string>& inputs) -> vector<int>
{
    vector<int> int_inputs;
    int_inputs.push_back(stoi(inputs[0]) + 1);
    int_inputs.push_back(stoi(inputs[1]));

    inputs.erase(inputs.begin());
    inputs.erase(inputs.begin());

    return int_inputs;
}

auto get_nodes(vector<string>& inputs) -> vector<int>
{   
    int from, to;
    vector<int> data;
    istringstream ss(inputs[0]);
    ss >> from >> to;

    data.push_back(from);
    data.push_back(to);

    inputs.erase(inputs.begin());

    return data;
}

auto make_map(const int map_size, const int pair_number, vector<string>& inputs) -> Map
{
    Map map(map_size, vector<int>());

    for (int i = 0; i < pair_number; i++)
    {   
        auto data = get_nodes(inputs);
        int from = data[0];
        int to = data[1];

        map[from].push_back(to);
        map[to].push_back(from);
    }

    return map;
}

auto make_map_from_file() -> Map
{   
    auto inputs = read_file();
    auto int_inputs = separate_int_inputs(inputs);

    int map_size = int_inputs[0];
    int pair_number = int_inputs[1];

    Map map = make_map(map_size, pair_number, inputs);

    return map;
}

auto is_visited(const vector<bool>& visit, int node) -> bool
{
    return visit[node] == false;
}

auto search_infection(const int node, int& cnt, const Map& map, vector<bool>& visit) -> void
{
    visit[node] = true;
    cnt++;

    for (int neighbor : map[node])
        if (is_visited(visit, neighbor)) search_infection(neighbor, cnt, map, visit);
}

auto count_infected_computer(Map& map) -> int
{
    int cnt = 0;
    int start_node = 1;
    vector<bool> visit(map.size(), false);

    search_infection(start_node, cnt, map, visit);

    int result = cnt - 1;   // 시작 노드 제외

    return result;
}