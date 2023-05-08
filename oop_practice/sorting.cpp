#include <iostream>
#include <algorithm>

using namespace std;

// NOTICE
// 이 예제가 객체지향 공부로서 가치가 있으려면 여러 소팅 알고리즘이 데이터에 따라서
// 최적화된 방법으로 선택되게 하면 좋을 것 같습니다. 이를테면, 
// 1) quicksort가 대부분의 데이터가 정렬된 경우 O(n^2)이고
// 2) 제한된 개수의 정수가 있을 경우 count sort O(n)
// 등등
class Sort{
public:
    Sort(int N);
    void sorting();
    void get_input();
    void print_result();

private:
    int N_line;        // 변수명의 일관성 int line_count;
    int arr[1001];     // no magic number
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

// 아래 함수는 너무 문제가 많습니다. 절대 이렇게 코딩하면 안됩니다.
// "모든 함수는 한 가지 일만 잘 해야한다"는 규칙에 완전히 위배됩니다.
// print_result라는 이름하에
// 1) input도 받고
// 2) 정렬도 하고
// 3) 사용자의 선택권이 없는 화면 출력
//
void Sort::print_result(){
    get_input();
    sorting();

    for(int i=1; i<=N_line; i++){
        cout << arr[i] << '\n';
    }
}

// 이 메인도 좀 더 의도가 있도록 짤 수 있습니다.
// 미리 간단한 난수를 발생시키거나, 10여개 정도의 정수를 직접 입력 등등해서 정렬 이후의 데이터를 관계 테스트 등
int main(){
    int Num_line;
    cin >> Num_line;

    Sort sorting(Num_line);
    sorting.print_result();

    return 0;

}


