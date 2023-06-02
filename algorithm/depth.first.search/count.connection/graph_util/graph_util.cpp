#include "graph_util.hpp"
#include "../file_util/file_util.hpp"

#include <iostream>
#include <sstream>

using namespace std;

auto get_parameter(vector<string>& inputs) -> vector<int>
{
    int node, edge;
    vector<int> parameter;
    istringstream iss(inputs[0]);

    iss >> node >> edge;
    parameter.push_back(node);
    parameter.push_back(edge);

    return parameter;
}

auto get_node(string nodes) -> vector<int>
{
    int from, to;
    vector<int> node;
    istringstream iss(nodes);

    iss >> from >> to;
    node.push_back(from);
    node.push_back(to);

    return node;
}

auto set_connection(Network& net, int const& edge, vector<string>& inputs) -> void
{
    for(int i = 0; i < edge; i++)
    {
        auto node = get_node(inputs[i+1]);
        net[node[0]].push_back(node[1]);
        net[node[1]].push_back(node[0]);
    }
}

auto make_network(int const& node, int const& edge, vector<string>& inputs) -> Network
{
    Network net(node+1, vector<int>());
    set_connection(net, edge, inputs);

    return net;
}

auto make_network_from_file(string const& fname) -> Network
{
    auto inputs = read_txt(fname);
    auto parameter = get_parameter(inputs);
    auto net = make_network(parameter[0], parameter[1], inputs);

    return net;
}

