#include <iostream>
#include <cmath>

using namespace std;

//  N-Queen: 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제

class N_Queens {
public:
    N_Queens(int _size)
        : size(_size),
          n_queen(0),
          counts(0),
          board(new int[_size]) {}

    auto go() -> bool 
    {
        for (int i = 0; i < n_queen; i++) 
        {
            if (board[n_queen] == board[i] || n_queen - i == abs(board[n_queen] - board[i]))
                return false;
        }
        return true;
    }

    auto backtrack() -> void 
    {
        if (n_queen == size) 
        {
            counts++;
        }

        for (int i = 0; i < size; i++) 
        {
            board[n_queen] = i;

            if (go()) 
            {
                n_queen = n_queen + 1;
                backtrack();
                n_queen = n_queen - 1; 
            }
        }
    }

    int get_count() const
    {
        return counts;
    }

private:
    int size;
    int n_queen;
    int counts;
    int* board;
};

int main() {
    N_Queens queens(5);
    queens.backtrack();
    cout << queens.go() << endl;
    
    return 0;
}
