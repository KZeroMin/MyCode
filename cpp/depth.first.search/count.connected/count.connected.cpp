#include "count.connected.hpp"
#include <cassert>

int main()
{
    Map map = make_map_from_file();
    auto component = count_component(map);
    
    assert(component == 2);

    return 0;
}