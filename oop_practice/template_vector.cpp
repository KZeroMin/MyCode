#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//  Todo
//  원하는 자료형의 type에 따라 유동적으로 데이터를 저장할 수 있도록 해보자 -> input을 우선 string형태로 받도록 구현
//  컴파일러가 T 부분에 원하는 타입으로 채워서 코드를 생성한다 -> C++에서는 이를 template이라는 이름으로 지원하고 있다
//  확장 가능성: input data를 저장하는 요소로 template vector를 사용하는 객체를 생성할 경우, 사용될 수 있을 것

// REMARK
// 문법을 이렇게 공부해볼 수는 있지만, 실용성이 좀 부족한 클래스입니다
// 리뷰를 해보면
// 1. Template는 주로 해더 안에서 처리합니다. 지금처럼 구현을 밖으로 뽑아내지말고, 간명하게 자바처럼 클래스 안에서 다 처리해도 됩니다.
// 2. VectorCreator는 좋은 이름이 아닙니다. 이 클래스 이름을 본 사람이 무엇을 생각할지 다시 생각해 보세요.
// 3. getInputString() 함수는 이 클래스의 멤버일 필요가 없습니다.
// 4. createVectorFromInput 함수가 실은 이 클래스의 핵심 기능을 가지고 있는데 이것은 아래처럼 함수로 끝내면 될 것 같아요
//    실제로 의미가 있는 T는 string 정도일 듯 해서 다음의 함수도 생각해보시기 바랍니다.

namespsace {
    auto split(string in, char delim) -> vector<string>
    {
        vector<string> result;
        stringstream ss(in);

        string item;
        while (getline(ss, item, delim))
            result.push_back(item);

        return result;
    }
}

// 5.createVectorFromInput 이 클래스에 있을필요가 없습니다.
// 미루어 짐작컨데 인자가 없는 다음의 함수를 짜고싶었던 것 아니었나요?
// string VectorCreator<T>::ToString()


template <typename T>
class VectorCreator {
public:
    string getInputString();
    vector<T> createVectorFromInput(const string& inputString); // const를 사용함으로써, 함수 내부에서 맴버 변수를 수정할 수 없도록 할 수 있다.
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
