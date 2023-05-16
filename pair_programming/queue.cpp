#include <iostream>
#include <deque>

using namespace std;

template <typename T>
class Queue
{
public:
    void push(const T& element){
        elements.push_back(element);
    }

    void pop()
    {
        if(elements.size() != 0)
        {
            elements.pop_front();
        }
    }

    void front()
    {
        if(elements.size() != 0)
        {
            cout << elements.front() << endl;
        }
    }

    void back()
    {
        if(elements.size() != 0)
        {
            cout << elements.back() << endl;
        }
    }

    bool empty()
    {
        return elements.size() == 0;
    }

private:
    deque<T> elements;
};

int main()
{
    Queue<int> int_queue;
    int_queue.push(1);
    int_queue.push(2);
    int_queue.back();
    int_queue.push(3);
    int_queue.push(4);
    int_queue.front();

    int_queue.pop();
    int_queue.front();
    cout << int_queue.empty() << endl;

    return 0;    
}