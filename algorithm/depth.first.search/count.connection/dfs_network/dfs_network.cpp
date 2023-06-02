#include "dfs_network.hpp"
#include "../file_util/file_util.hpp"

#include <iostream>

using namespace std;

auto count_network(Network& net, vector<bool>& visit, int& node, int& cnt) -> void
{
    if(visit[node]) return;

    visit[node] = true;
    cnt++;

    for(int new_node : net[node])
        count_network(net, visit, new_node, cnt);
}

auto get_number_of_network(Network& net) -> int
{
    int number_of_network = 0;
    vector<bool> visit(net.size(), false);

    for(int i = 1; i < net.size(); i++)
    {
        int cnt = 0;
        count_network(net, visit, i, cnt);
        if(cnt > 0) number_of_network++;
    }

    return number_of_network;
}