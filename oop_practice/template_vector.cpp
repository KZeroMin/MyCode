#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
// REMARK
// 1. Template는 주로 해더 안에서 처리합니다. 지금처럼 구현을 밖으로 뽑아내지말고, 간명하게 자바처럼 클래스 안에서 다 처리해도 됩니다.
// 2. VectorCreator는 좋은 이름이 아닙니다. 이 클래스 이름을 본 사람이 무엇을 생각할지 다시 생각해 보세요.
// 3. getInputString() 함수는 이 클래스의 멤버일 필요가 없습니다.
// 4. createVectorFromInput 함수가 실은 이 클래스의 핵심 기능을 가지고 있는데 이것은 아래처럼 함수로 끝내면 될 것 같아요
//    실제로 의미가 있는 T는 string 정도일 듯 해서 다음의 함수도 생각해보시기 바랍니다.


// 문자열을 구분자를 사용하여 분리하는 함수 -> 아래 생성한 class가 결국 불필요한 class가 되는 근거, 구지 class로 만들필요가 없다
auto split(string in, char delim) -> vector<string>
{
    vector<string> result;
    stringstream ss(in);

    string item;
    while (getline(ss, item, delim))
        result.push_back(item);

    return result;
}

// Vector class가 의미가 있으려면, Vector자체 기능(push_back, remove..와 같은 맴버함수들을 포함하고 있어야 할것이다.)
template <typename T>
class StringVector {

public:
    vector<T> createVectorFromInput(const string& inputString) {
        container.clear(); // 멤버 변수 초기화

        istringstream separator(inputString);

        while (separator >> inputData) {
            container.push_back(inputData);
        }

        return container;
    }

    string printVectorToString() {
        stringstream result;
        for (const auto& element : container) {
            result << element << " ";
        }
        return result.str();
    }

private:
    vector<T> container;
    T inputData;
};

int main() {
    StringVector<string> creator; // 템플릿 인자로 원하는 자료형을 지정, 여기서는 string 타입으로 설정

    cout << "Enter values (separated by spaces): ";
    string inputString;
    getline(cin, inputString);
    creator.createVectorFromInput(inputString);

    cout << "Vector values (separated by spaces): " << creator.printVectorToString() << "\n";

    return 0;
}