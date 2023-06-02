#include <iostream>
#include <deque>

using namespace std;

template <typename T>
class Stack
{
public:
    void push(const T& element)
    {
        elements.push_back(element);
    }

    void pop() 
    {
        if(elements.size() > 0)
        {
            elements.pop_back();
        }
        else
        {
            throw out_of_range("Stack is empty");
        }
    }

    T top()const    // const를 추가함으로써 맴버 변수 수정 못하도록
    {
        if(elements.size() > 0){
            return elements.back();
        }
        else{
            throw out_of_range("Stack is empty");
        }
    }

    int size()const
    {
        return elements.size();
    }

    bool empty()const
    {
        return elements.size() == 0;
    }

private:
    deque<T> elements;
};