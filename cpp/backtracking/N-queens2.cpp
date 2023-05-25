#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;    

//  N-queens, but no class
int count = 0;

auto go(int *board, int n_queen) -> bool const
{
    for (int i = 0; i < n_queen; i++)
    {
        if (board[n_queen] == board[i] || n_queen - i == abs(board[n_queen] - board[i]))
            return false;
    }

    return true;
}

auto backtrack(int *board, int length, int n_queen) -> int
{
    for (int i = 0; i < length; i++)
    {
        board[n_queen] = i;

        if (n_queen == length)
        {
            count++;
            return 0;
        }

        if (go(board, n_queen))
        {
            n_queen++;
            backtrack(board, length, n_queen);
            n_queen--; 
        }
    }

    return count;
}


auto get_count() -> int const
{
    return count;
}


int main()
{   
    int result;
    int count = 0;
    int length = 8;
    int *board = new int[length];

    backtrack(board, length, 0);
    result = get_count();
    assert(result = 92);
    delete[] board;

    return 0;
}