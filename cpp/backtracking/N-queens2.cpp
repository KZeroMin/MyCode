#include <iostream>
#include <cmath>

using namespace std;    

//  N-queens, but no class

auto go() -> bool const
{
    for (int i = 0; i < n_queen; i++)
    {
        if (board[n_queen] == board[i] || n_queen - i == abs(board[n_queen] - board[i]))
            return false;
    }

    return true;
}

auto backtrack(int *board, int length, int n_queen, int count) -> int
{
    for (int i = 0; i < length; i++)
    {
        board[n_queen] = i;

        if (n_queen == length)
        {
            count++;
            return 0;
        }

        if (go())
        {
            n_queen++;
            backtrack();
            n_queen--; 
        }
    }

    return 0;
}

auto get_count() -> int const
{
    return count;
}

int main()
{
    int length = 8;
    int *board = new int[length];

    backtrack();
    cout << get_count(board, length, 0, 0) << endl;

    delete[] board;

    return 0;
}
