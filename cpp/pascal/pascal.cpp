#include <iostream>
#include <vector>

using namespace std;

class Pascal
{
public:
    Pascal (int size) : size_of_pascal(size), pascal_elements(size, vector<int>(size, 0)) {} // use member initializer

    void calculate_combination()
    {
        for (int row = 0; row < size_of_pascal; row++)
        {
            for (int column = 0; column <= row; column++)
            {
                if (column == 0 || column == row)
                    pascal_elements[row][column] = 1;
                else
                    pascal_elements[row][column] = pascal_elements[row - 1][column - 1] + pascal_elements[row - 1][column];
            }
        }
    }

    auto make_pascal_into_string () -> string
    {
        string pascal_string;

        for (const auto& row : pascal_elements)
        {
            for (const auto& element : row)
            {
                if (element != 0) pascal_string = pascal_string + to_string(element) + " ";  
                else break;
            }
            pascal_string += '\n';
        }

        return pascal_string;
    }

private:
    int size_of_pascal;
    vector<vector<int>> pascal_elements;
};


int main()
{
    Pascal pascal(10);
    pascal.calculate_combination();
    cout << pascal.make_pascal_into_string();
    
    return 0;
}