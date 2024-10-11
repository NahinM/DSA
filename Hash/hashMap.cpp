#include <iostream>
using namespace std;

#define br cout << '\n'
#define repti(a,b) for(int i = a; i < b; i++)

class Node
{
public:
    string key;
    int value;
    Node *next = nullptr;
    Node(string k, int v){
        key = k;
        value = v;
    }
};

class LinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int listSize = 0;
public:
    void push(string k,int v);
    Node* getList();
    int size();
    void remove(string k);
    void printList();
};

Node* LinkedList::getList(){
    return head;
}

int LinkedList::size(){
    return listSize;
}

void LinkedList::push(string k,int v){
    listSize++;
    if(head==nullptr){
        head = new Node(k,v);
        tail = head;
        return;
    }
    tail->next = new Node(k,v);
    tail = tail->next;
}

void LinkedList::remove(string k){
    if(head == nullptr){
        cout << "The list is empty\n";
        return;
    }
    if(head->key == k){
        Node *tem = head;
        head = head->next;
        delete tem;
        listSize--;
        return;
    }
    Node *tem = head;
    while (tem->next != nullptr)
    {
        if(tem->next->key == k){
            Node *del = tem->next;
            tem->next = del->next;
            delete del;
            listSize--;
            return;
        }
        tem = tem->next;
    }
    cout << "The key is not in the list\n";
    return;
}

void LinkedList::printList(){
    Node *tem = head;
    while (tem != nullptr)
    {
        cout << tem->key << " : " << tem->value << ' ';
        tem = tem->next;
    }br;
}

class HashMap
{
private:
    LinkedList arr[10];
    int capacity = 10;
    int size = 0;
public:
    int hash_fun(string key);
    void insert(string key,int value);
    void remove(string key);
    void print();
};

void HashMap::print(){
    repti(0,capacity) {
        cout << i << " -> ";
        arr[i].printList();
    }br;
}

int HashMap::hash_fun(string key){
    int sum = 0;
    for(char c : key) sum += (int)c;
    return sum % capacity;
}

void HashMap::insert(string key,int value){
    int index = hash_fun(key);
    arr[index].push(key,value);
    size++;
}

void HashMap::remove(string key){
    int index = hash_fun(key);
    arr[index].remove(key);
    size--;
}

int main(){
    HashMap map;
    map.insert("alex", 11111);
    map.insert("bob",22222);
    map.insert("shark",33333);
    map.insert("lily",44444);
    map.insert("nahin",66666);
    map.print();
    map.remove("alex");
    map.print();
}
