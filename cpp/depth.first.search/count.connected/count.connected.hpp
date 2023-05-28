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
    int r, l;

    while(!in.fail())
    {
        getline(in, line);
        istringstream iss(line);
        iss >> r >> l;

        inputs.push_back(r);
        inputs.push_back(l);
    }

    return inputs;
}

auto set_connection(Map& map, vector<int> inputs, const int edge) -> void
{
    for (int i = 0; i < edge; i++)
    {
        map[inputs[2 + 2 * i]].push_back(inputs[3 + 2 * i]);
        map[inputs[3 + 2 * i]].push_back(inputs[2 + 2 * i]);
    }
}

auto make_map(vector<int>& inputs) -> Map
{   
    Map map(inputs[0]+1, vector<int>());
    set_connection(map, inputs, inputs[1]);

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