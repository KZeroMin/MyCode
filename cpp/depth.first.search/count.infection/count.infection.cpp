#include "count.infection.hpp"

//  문제:
//  1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 구한다

int main()
{
    Map map = make_map_from_file();
    auto infection = count_infected_computer(map);
    assert(infection == 4); 

    return 0;
}