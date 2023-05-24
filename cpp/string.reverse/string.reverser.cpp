#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class StringReverser
{
public:
    StringReverser(string _input)
                : input(_input)
    {};

    StringReverser() = delete;
    
    auto reverse() -> string
    {
        string result = input;
        int l = 0;
        int r = result.length() - 1;

        for (int l = 0; l < r; l++)
        {   
            if (left == right) break;

            char temp = result[r];
            result[r] = result[l];
            result[l] = temp;

            r -= 1;
        }

        return result;
    }

private:
    string input;
};

int main()
{
    string input = "Hello world!";

    StringReverser reverser(input);
    string output = reverser.reverse();

    cout << output << endl;
    assert(output == "!dlrow olleH");


    return 0;
}