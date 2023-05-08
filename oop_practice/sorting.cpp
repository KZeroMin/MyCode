#include <iostream>
#include <algorithm>

using namespace std;

class Sort{
public:
    Sort(int N);
    void sorting();
    void get_input();
    void print_result();

private:
    int N_line;
    int arr[1001];
};

Sort::Sort(int N){
    N_line = N;
}

void Sort::get_input(){
    for(int i=1; i<=N_line; i++){
        cin >> arr[i];
    }
}

void Sort::sorting(){
    sort(arr+1, arr+N_line+1);
}

void Sort::print_result(){
    for(int i=1; i<=N_line; i++){
        cout << arr[i] << '\n';
    }
}

int main(){
    int Num_line;
    cin >> Num_line;

    Sort sorting(Num_line);
    sorting.get_input();
    sorting.sorting();
    sorting.print_result();

    return 0;

}


