#include <iostream>
#include <vector>

using namespace std;

//
// refactor pascal.cpp with feedback, and fast speed.
//


class Pascal
{
public:
    Pascal(int _height) 
        : height(_height)
        , elements(_height, vector<int>(_height, 0))
    {}

    Pascal() = delete;

    void build()
    {
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col <= row; col++)
            {
                elements[row][col] = (col == 0 || row == col) 
                    ? 1
                    : elements[row-1][col-1] + elements[row-1][col]; 
            }
        }
    }

    auto to_s() -> string
    {
        string result = {};

        for (const auto& row : elements)
        {
            for (const auto& element : row)
            {
                if (element != 0)
                    result += (to_string(element) + " ");
                else
                    break;
            }

            result += "\n";
        }

        return result;
    }

private:
    int height;
    vector<vector <int>> elements;
};

int main()
{
    Pascal pascal(10);
    pascal.build();
    cout << pascal.to_s();

    return 0;
}