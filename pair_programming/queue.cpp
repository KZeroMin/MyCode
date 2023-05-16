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
        else
        {
            throw out_of_range("Queue is empty!");
        }
    }

    T front()
    {
        if(elements.size() != 0)
        {
            return elements.front();
        }
        else
        {
            throw out_of_range("Queue is empty!");
        }
    }

    T back()
    {
        if(elements.size() != 0)
        {
            return elements.back();
        }
        else
        {
            throw out_of_range("Queue is empty!");
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
    int_queue.pop();
    int_queue.push(1);
    int_queue.push(2);
    cout << int_queue.back() << endl;
    int_queue.push(3);
    int_queue.push(4);
    cout << int_queue.front() << endl;

    int_queue.pop();
    cout << int_queue.front() << endl;
    cout << int_queue.empty() << endl;

    return 0;    
}