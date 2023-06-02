#pragma once

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using Map = vector<vector<int>>;

auto read_file() -> vector<string>
{
    vector<string> inputs;
    ifstream in("input.txt");
    string line;

    while(!in.fail())
    {
        getline(in, line);
        inputs.push_back(line);
    }

    return inputs;
}

auto get_parameter(vector<string>& inputs) -> vector<int>
{
    int node, edge, start_node;
    vector<int> parameter;
    istringstream iss(inputs[0]);
    
    iss >> node >> edge >> start_node;
    parameter.push_back(node);
    parameter.push_back(edge);
    parameter.push_back(start_node);

    return parameter;
}

auto get_node(string& input) -> vector<int>
{   
    istringstream iss(input);
    vector<int> nodes;
    int from, to;

    iss >> from >> to;
    nodes.push_back(from);
    nodes.push_back(to);

    return nodes;
}

auto set_connection(Map& map, vector<int>& nodes) -> void
{
    map[nodes[0]].push_back(nodes[1]);
    map[nodes[1]].push_back(nodes[0]);
}

auto make_map(int& node, int& edge, vector<string> inputs) -> Map
{
    Map map(node+1, vector<int>());

    for (int i = 1; i <= edge; i++)
    {
        auto nodes = get_node(inputs[i]);
        set_connection(map, nodes);
    }

    return map;
}

auto make_map_from_file() -> Map
{
    auto inputs = read_file();
    auto parameter = get_parameter(inputs);
    Map map = make_map(parameter[0], parameter[1], inputs);

    return map;
}

auto to_dfs(Map& map, vector<bool>& visit, vector<int>& tour, int node) -> void
{
    visit[node] = true;
    tour.push_back(node);

    sort(map[node].begin(), map[node].end());

    for (int new_node : map[node])
    {
        if (!visit[new_node])
            to_dfs(map, visit, tour, new_node);
    }
}

auto to_bfs(Map& map, vector<bool>& visit, vector<int>& tour, int start_node) -> void
{
    queue<int> q;
    q.push(start_node);
    visit[start_node] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        tour.push_back(node);

        sort(map[node].begin(), map[node].end());

        for (int new_node : map[node])
        {
            if (!visit[new_node])
            {
                q.push(new_node);
                visit[new_node] = true;
            }
        }
    }
}

auto tour_tree_dfs(Map& map, int start_node) -> vector<int>
{
    vector<bool> visit(map.size(), false);
    vector<int> tour;

    to_dfs(map, visit, tour, start_node);

    return tour;
}

auto tour_tree_bfs(Map& map, int start_node) -> vector<int>
{
    vector<bool> visit(map.size(), false);
    vector<int> tour;

    to_bfs(map, visit, tour, start_node);

    return tour;
}

auto set_start() -> int
{
    int node, edge, start;
    ifstream in("input.txt");
    string line;
    getline(in, line);

    istringstream iss(line);
    iss >> node>> edge >> start;

    return start;
}