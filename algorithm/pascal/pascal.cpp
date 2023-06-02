#include <iostream>
#include <vector>

using namespace std;

class Pascal
{
public:
    Pascal(int size) 
        : height(size)
        , elemets(size, vector<int>(size, 0)) 
    {} // use member initializer

    Pascal() = delete;  //  기본 생성자를 삭제함으로써 호출을 금지

    void build()
    {
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col <= row; col++)
            {
                elemets[row][col] = (col == 0 || col == row)
                    ? 1
                    : elemets[row - 1][col - 1] + elemets[row - 1][col];
            }
        }
    }

    auto to_s() -> string
    {
        string result{};

        for (const auto& row : elemets)
        {
            for (const auto& element : row)
            {
                if (element == 0) 
                    break;

                result += to_string(element) + " ";  
            }
            
            result += '\n';
        }

        return result;
    }

private:
    int height;
    vector<vector<int>> elemets;
};

int main()
{
    Pascal pascal(10);
    pascal.build();
    cout << pascal.to_s();

    return 0;
}
