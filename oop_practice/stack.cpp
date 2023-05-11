#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack{
public:
    void push(const T& element){
        elements.push_back(element);
    }

    void pop() {
        if(elements.size() > 0){
            elements.pop_back();
        }
        else{
            throw out_of_range("Stack is empty");
        }
    }

    T top()const{    // const를 추가함으로써 맴버 변수 수정 못하도록
        if(elements.size() > 0){
            return elements.back();
        }
        else{
            throw out_of_range("Stack is empty");
        }
    }

    int size()const{
        return elements.size();
    }

    bool empty()const{
        return elements.size() == 0;
    }

private:
    vector<T> elements;
};

int main(){
    Stack<int> intStack;

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);
    
    cout << "Size of intStack: " << intStack.size() << endl;
    cout << "Top element of intStack: " << intStack.top() << endl;

    intStack.pop();
    intStack.pop();

    cout << "Verify intStack is empty: " << intStack.empty() << endl;
    cout << "Size of intStack after pop: " << intStack.size() << endl;
    cout << "Top element of intStack after pop: " << intStack.top() << endl;

}