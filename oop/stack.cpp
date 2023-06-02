#include <iostream>
#include "stack.h"

using namespace std;

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

    return 0;
}