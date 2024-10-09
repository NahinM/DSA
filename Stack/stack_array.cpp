#include <iostream>
using namespace std;

#define br cout << '\n'
#define repti(a,b) for(int i = a; i < b; i++)

class Stack
{
private:
    int *arr = new int[1];
    int stackSize = 0;
    int capacity = 1;
    int head = 0;
public:
    void push(int d);
    int top();
    void pop();
    bool empty();
    int size();
};

bool Stack::empty(){
    return stackSize == 0;
}

int Stack::size(){
    return stackSize;
}

void Stack::push(int d){
    if(stackSize == capacity){
        int *tem = new int[capacity*2];
        for(int i = 0; i < capacity; i++){
            tem[i] = arr[i];
        }
        delete[] arr;
        arr = tem;
        capacity *= 2;
    }
    arr[head++] = d;
    stackSize++;
}

int Stack::top(){
    return arr[head-1];
}

void Stack::pop(){
    head--;
    stackSize--;
}

int main(){
    Stack stk = Stack();
    repti(1,6) stk.push(i);
    cout << "Size of stack: " << stk.size();br;
    while (!stk.empty())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }
    br;
    cout << "Size of stack: " << stk.size();br;
}