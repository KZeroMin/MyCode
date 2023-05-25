#include <iostream>
#include <cmath>

using namespace std;

class N_Queens {
public:
    N_Queens(int _size)
        : size(_size),
          cnt(0),
          counts(0),
          board(new int[_size]) {}

    auto check() -> bool 
    {
        for (int i = 0; i < cnt; i++) 
        {
            if (board[cnt] == board[i] || cnt - i == abs(board[cnt] - board[i]))
                return false;
        }
        return true;
    }

    auto backtrack() -> void 
    {
        if (cnt == size) 
        {
            counts++;
        }

        for (int i = 0; i < size; i++) 
        {
            board[cnt] = i;

            if (check()) 
            {
                cnt = cnt + 1;
                backtrack();
                cnt = cnt - 1; // backtracking을 위해 이전 상태로 돌아감
            }
        }
    }

    int get_count() const
    {
        return counts;
    }

private:
    int size;
    int cnt;
    int counts;
    int* board;
};

int main() {
    N_Queens queens(5);
    queens.backtrack();
    cout << queens.get_count() << endl;
    return 0;
}
