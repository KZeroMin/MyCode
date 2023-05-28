#include "count.connected.hpp"

int main()
{
    Map map = make_map_from_file();
    auto component = count_component(map);

    cout << component;

    return 0;
}