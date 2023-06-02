#include "file_util/file_util.hpp"
#include "graph_util/graph_util.hpp"
#include "dfs_network/dfs_network.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main(int, char**) {
    auto net = make_network_from_file("../input.txt");
    auto number_of_network = get_number_of_network(net);
    assert(number_of_network == 2);
    cout << "Network number: " << number_of_network << endl;

    return 0;
}
