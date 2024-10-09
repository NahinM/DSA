#include <iostream>
using namespace std;

#define br cout << '\n'
#define repti(a,b) for(int i=a;i<b;i++)

class Node
{
public:
    int data;
    Node *pre = nullptr;
    Node *next = nullptr;
    Node(int d){
        data = d;
    }
};

class doublyLinkedList
{
private:
    int listSize = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    void push(int d);
    void addAt(int d,int at);
    void deleteAt(int at);
    int size();
    void printtList();
    void printRev();
    bool empty();
};

bool doublyLinkedList::empty(){
    return head == nullptr;
}

void doublyLinkedList::push(int d){
    listSize++;
    if(head == nullptr){
        head = new Node(d);
        tail = head;
        return;
    }
    tail->next = new Node(d);
    tail->next->pre = tail;
    tail = tail->next;
}

void doublyLinkedList::addAt(int d,int at){
    if(at<0 || at>listSize){
        cout << "invalid index\n";
        return;
    }
    Node *tem = head;
    listSize++;
    if(at == 0){
        head = new Node(d);
        head->next = tem;
        tem->pre = head;
        return;
    }
    repti(0,at-1)tem = tem->next;
    Node *r = tem->next;
    tem->next = new Node(d);
    tem->next->pre = tem;
    if(tail->next != nullptr) tail = tail->next;
    if(r == nullptr) return;
    tem = tem->next;
    tem->next = r;
    r->pre = tem;
}

void doublyLinkedList::deleteAt(int at){
    if(at<0 || at>=listSize){
        cout << "invalid index\n";
        return;
    }
    Node *l = nullptr, *r = tail,*terget = head;
    listSize--;
    if(at == 0){
        head = head->next;
        head->pre = nullptr;
        delete terget;
        return;
    }
    if(at == listSize){
        tail = tail->pre;
        tail->next = nullptr;
        delete r;
        return;
    }
    repti(0,at) terget=terget->next;
    l = terget->pre;
    r = terget->next;
    if(l != nullptr) l->next = r;
    if(r != nullptr) r->pre = l;
    delete terget;
}

int doublyLinkedList::size(){
    return listSize;
}

void doublyLinkedList::printtList(){
    if(head == nullptr){
        cout << "this list is empty!\n";
        return;
    }
    Node *tem = head;
    while(tem != nullptr){
        cout << tem->data << ' ';
        tem = tem->next;
    }br;
}

void doublyLinkedList::printRev(){
    Node *tem = tail;
    while(tem != nullptr){
        cout << tem->data << ' ';
        tem = tem->pre;
    }br;
}

int main(){
    freopen("listData.txt" , "r" , stdin);

    int n,a;
    doublyLinkedList dll = doublyLinkedList();
    cin >> n;
    repti(0,n){
        cin >> a;
        dll.push(a);
    }
    dll.printtList();
    dll.addAt(10,5);
    dll.printtList();
    dll.deleteAt(4);
    dll.printtList();
    dll.printRev();
}