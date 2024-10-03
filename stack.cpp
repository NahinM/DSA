#include <iostream>
using namespace std;

#define br cout << '\n'

class Node
{
public:
    int data = 0;
    Node *next = nullptr;
    Node(int d){
        data = d;
    }
};

class Stack
{
private:
    Node *head = nullptr;
    int stackSize = 0;
public:
    void push(int d);
    int top();
    void pop();
    bool empty();
    int size();
};

bool Stack::empty(){
    return head == nullptr;
}

int Stack::size(){
    return stackSize;
}

void Stack::push(int d){
    Node *tem = new Node(d);
    tem->next = head;
    head = tem;
    stackSize++;
}

int Stack::top(){
    return head->data;
}

void Stack::pop(){
    Node *tem = head;
    head = head->next;
    delete tem;
    stackSize--;
}

int main(){
    freopen("input.txt","r",stdin);
    cout << "Enter the amount of data: ";br;
    int n,a;
    cin >> n;
    Stack stk = Stack();
    cout << "Enter your data one by one: ";br;
    while (n-- && cin >> a) stk.push(a);
    while(!stk.empty()){
        cout << stk.top() << ' ';
        stk.pop();
    }br;
    
    return 0;
}