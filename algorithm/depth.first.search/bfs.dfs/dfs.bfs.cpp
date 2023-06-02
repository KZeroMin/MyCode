#include "bfs.dfs.hpp"

int main()
{
    Map map = make_map_from_file();
    auto dfs_tour = tour_tree_dfs(map, set_start());
    auto bfs_tour = tour_tree_bfs(map, set_start());

    for (int node : dfs_tour)
        cout << node << " ";

    cout << endl;

    for (int node : bfs_tour)
        cout << node << " ";

    return 0;
}