#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//  Todo
//  원하는 자료형의 type에 따라 유동적으로 데이터를 저장할 수 있도록 해보자 -> input을 우선 string형태로 받도록 구현
//  컴파일러가 T 부분에 원하는 타입으로 채워서 코드를 생성한다 -> C++에서는 이를 template이라는 이름으로 지원하고 있다
//  확장 가능성: input data를 저장하는 요소로 template vector를 사용하는 객체를 생성할 경우, 사용될 수 있을 것

template <typename T>
class VectorCreator {
public:
    string getInputString();
    vector<T> createVectorFromInput(const string& inputString);
    string printVectorToString(const vector<T>& container);

private:
    vector<T> container;
    T inputData;
    string inputString;
};

template <typename T>
string VectorCreator<T>::getInputString() {
    getline(cin, inputString);

    return inputString;
}

template <typename T>
vector<T> VectorCreator<T>::createVectorFromInput(const string& inputString) {
    istringstream separator(inputString);

    while (separator >> inputData) {
        container.push_back(inputData);
    }

    return container;
}

template <typename T>
string VectorCreator<T>::printVectorToString(const vector<T>& container) {
    stringstream result;
    for (const auto& element : container) {
        result << element << " ";
    }
    return result.str();
}


//  보충 예정 사항
//  type별로 case를 만들어서 다른 input type에도 동작하도록(switch..case..)
//  출력 형태를 string으로 만들어서 출력하도록(checked!)
//  etc..
int main() {
    VectorCreator<char> creator; // 템플릿 인자로 원하는 자료형을 지정, char

    cout << "Enter values (separated by spaces): ";
    string inputString = creator.getInputString();
    vector<char> result = creator.createVectorFromInput(inputString);

    cout << "Vector values (separated by spaces): " << creator.printVectorToString(result) << "\n";

    return 0;
}