#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using Map = vector<vector<int>>;



auto read_file() -> vector<int>
{
    ifstream in("input.txt");
    vector<int> inputs;
    string line;
    int num1, num2;

    while(!in.fail())
    {
        getline(in, line);
        istringstream iss(line);
        iss >> num1 >> num2;

        inputs.push_back(num1);
        inputs.push_back(num2);
    }

    return inputs;
}

auto set_node_connection(Map& map, vector<int> inputs) -> void
{
    cout << "edge number: " << inputs[0] << endl;
    int edge = inputs[0];
    inputs.erase(inputs.begin());

    for (int i = 0; i < edge; i++)
    {
        int from = inputs[0];
        int to = inputs[1];

        cout << from << " " << to << endl;

        map[from].push_back(to);
        map[to].push_back(from);

        inputs.erase(inputs.begin());
        inputs.erase(inputs.begin());
    }
}

auto make_map(vector<int>& inputs) -> Map
{   
    cout << "node number: " << inputs[0] + 1 << endl;
    Map map(inputs[0]+1, vector<int>());
    inputs.erase(inputs.begin());

    set_node_connection(map, inputs);

    return map;
}

auto make_map_from_file() -> Map
{
    auto inputs = read_file();
    Map map = make_map(inputs);

    return map;
}

auto is_visited(vector<bool>& visit, int& node) -> bool
{
    if (visit[node] != false) return false;

    return true;
}

auto do_dfs(Map& map, vector<bool>& visit, int& node, int& cnt) -> void
{
    cnt++;
    visit[node] = true;
    
    for (int new_node : map[node]) 
        if (is_visited(visit, new_node)) do_dfs(map, visit, new_node, cnt);
}

auto count_component(Map& map) -> int
{
    int component = 0;
    vector<bool> visit(map.size(), false);

    for (int i = 1; i < map.size(); i++)
    {   
        int cnt = 0;
        if (is_visited(visit, i)) do_dfs(map, visit, i, cnt);
        if (cnt > 0) component++;
    }

    return component;
}