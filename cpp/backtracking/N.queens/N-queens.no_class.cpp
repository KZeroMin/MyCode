#include <iostream>
#include <cassert>
#include <cmath>
#include <memory>

using namespace std;    

// NOTICE:
// anonymous namespace is same as static function in C language
// 익명 네임스페이스에서 정의한 함수들은 동일한 파일 내의 다른 함수에서 호출 가능
namespace 
{
    auto go(int *board, int n_queen) -> bool 
    {
        for (int i = 0; i < n_queen; i++)
        {
            if (board[n_queen] == board[i] || n_queen - i == abs(board[n_queen] - board[i]))
                return false;
        }

        return true;
    }

    auto do_backtrack(int *board, int length, int n_queen, int& count) -> int
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
                do_backtrack(board, length, n_queen, count);
                n_queen--; 
            }
        }

        return count;
    }
}

auto backtrack(int size, int n_queen) -> int
{
    // N-queens, but no class
    // unique_ptr to clean the dynamically allocated memory
    int count = 0;
    unique_ptr<int[]> board(new int[size]); 

    return do_backtrack(board.get(), size, n_queen, count);
}

int main()
{   
    auto result = backtrack(8, 0);
    assert(result = 92);

    return 0;
}
