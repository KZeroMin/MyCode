#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

// NOTICE(Todo)
// 이 예제가 객체지향 공부로서 가치가 있으려면 여러 소팅 알고리즘이 데이터에 따라서
// 최적화된 방법으로 선택되게 하면 좋을 것 같습니다. 이를테면, 
// 1) quicksort가 대부분의 데이터가 정렬된 경우 O(n^2)이고
// 2) 제한된 개수의 정수가 있을 경우 count sort O(n)
// 등등

class Sort {
public:
    Sort(int N);
    void generate_random_numbers();
    void add_numbers_to_vector();
    void sorting();
    void print_result();

private:
    int line_count;  // 변수명의 일관성 int line_count (Check)
    vector<int> number_container;  // array -> vector 형태로 바꾸면서, 크기를 동적으로 조절가능하도록 한다.
    vector<int> random_numbers;
};

Sort::Sort(int N) : line_count(N) {
    number_container.reserve(line_count);   // vector 메모리 할당
}

void Sort::generate_random_numbers() {
    random_device rd;   // 난수 생성 장치
    mt19937 gen(rd());   // 난수 생성 엔진
    uniform_int_distribution<int> dis(1, 100);  // 범위 [1, 100]의 정수 난수 분포

    for (int i = 0; i < line_count; i++) {
        int num = dis(gen);
        random_numbers.push_back(num);
    }
}

// 수정 필요
void Sort::add_numbers_to_vector() {
    for (int i = 0; i < line_count; i++) {
        number_container.push_back(random_numbers[i]);
    }
}

void Sort::sorting() {
    sort(number_container.begin(), number_container.end());
}

void Sort::print_result() {
    for (int i = 0; i < line_count; i++) {
        cout << number_container[i] << '\n';
    }
}

int main() {
    int Num_line;
    cout << "Enter the number of elements: ";
    cin >> Num_line;

    Sort sorting(Num_line);
    sorting.generate_random_numbers();
    sorting.add_numbers_to_vector();
    sorting.sorting();

    cout << "Sorted elements:\n";
    sorting.print_result();

    return 0;
}