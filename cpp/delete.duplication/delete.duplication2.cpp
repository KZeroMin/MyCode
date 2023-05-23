#include "delete.duplication.hpp"

int main()
{   
    string s = "my my name is is kim kim kim young min min this this order may may be broken broken broken";
    auto origin = convert_string_into_vector(s);
    auto out = join(get_unique_word(origin));
    
    assert(out == "be broken is kim may min my name order this young");

    return 0;
}

