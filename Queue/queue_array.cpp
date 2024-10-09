#include <iostream>
using namespace std;

#define br cout << '\n'
#define repti(a,b) for(int i = a; i < b; i++)

class Queue
{
private:
    int* arr = new int[2];
    int head = 0;
    int tail = 0;
    int capacity = 1;
    int queueSize = 0;

public:
    void push(int d);
    int front();
    int back();
    void pop();
    bool empty();
    int size();
};

void Queue::push(int d)
{
    if(capacity == queueSize){
        int* temp = new int[capacity * 2];
        for(int i = head; i < tail; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity *= 2;
    }
    arr[tail] = d;
    tail++;
    if(tail>capacity) tail = 0;
    queueSize++;
}

int Queue::front()
{
    return arr[head];
}

int Queue::back()
{
    return arr[tail - 1];
}

void Queue::pop()
{
    head = (head + 1) % capacity;
    queueSize--;
}

bool Queue::empty()
{
    return queueSize == 0;
}

int Queue::size()
{
    return queueSize;
}

int main(){
    Queue q;
    repti(1,6) q.push(i);
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    br;
    return 0;
}