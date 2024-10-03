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

class Queue
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int queueSize = 0;
public:
    void push(int d);
    void emplace(int d);
    int front();
    int back();
    void pop();
    bool empty();
    int size();
};

bool Queue::empty(){
    return head==nullptr;
}

int Queue::size(){
    return queueSize;
}

void Queue::push(int d){
    if(head == nullptr){
        head = new Node(d);
        tail = head;
        return;
    }
    tail->next = new Node(d);
    tail = tail->next;
    queueSize++;
}

void Queue::emplace(int d){
    if(head == nullptr){
        head = new Node(d);
        tail = head;
        return;
    }
    Node *tem = new Node(d);
    tem->next = head;
    head = tem;
}

int Queue::front(){
    return head->data;
}

int Queue::back(){
    return tail->data;
}

void Queue::pop(){
    Node *tem = head;
    head = head->next;
    delete tem;
    queueSize--;
}

int main(){
    freopen("input.txt","r",stdin);

    cout << "Enter the amount of data: ";br;
    int n,a;
    cin >> n;
    Queue q = Queue();
    cout << "Enter your data one by one: ";br;
    while (n-- && cin >> a) q.push(a);
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }br;

    return 0;
}