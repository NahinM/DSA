#include <iostream>
using namespace std;

#define br cout << '\n'
#define repti(a,b) for(int i=a;i<b;i++)

class Node
{
public:
    int data = 0;
    Node *next = nullptr;

    Node(int d){
        data = d;
    }
};

class linkedList
{
private:
    int sz = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    void push(int d);
    void addAt(int d,int at);
    void deleteAt(int at);
    int size();
    void readData(int n);
    void printList();
};


int linkedList::size(){
    return sz;
}

void linkedList::push(int d){
    // head is address
    // *head is the data at that address
    if(head == nullptr) {
        head = new Node(d);
        tail = head;
        sz++;
        return;
    }

    tail->next = new Node(d);
    tail = tail->next;
    sz++;
}

void linkedList::addAt(int d,int at){
    if(at < 0 || at>sz ){
        cout << "invalid index\n";
        return;
    }
    Node *tem = head,*right;
    if(at == 0){
        head = new Node(d);
        head->next = tem;
        return;
    }
    repti(0,at-1) tem = tem->next;
    right = tem->next;
    tem->next = new Node(d);
    tem->next->next = right;
}

void linkedList::deleteAt(int at){
    Node *tem = head,*terget;
    if(sz == 0 || head == nullptr){
        cout << "There is no data to delete\n";
        return;
    }
    if(at == 0){
        head = tem->next;
        delete tem;
    }
    repti(0,at-1)tem = tem->next;
    terget = tem->next;
    tem->next = terget->next;
    delete terget;
}

void linkedList::printList(){
    if(head == nullptr) {
        cout << "The list is empty\n";
        return;
    }
    Node *tem = head;
    while (tem != nullptr)
    {
        cout << tem->data << ' ';
        tem = tem->next;
    }br;
}

void linkedList::readData(int n){
    int a;
    cout << "Enter your list items one by one: ";br;
    while(n-- && cin >> a ) push(a);
}



int main(){
    freopen("input.txt","r",stdin);

    int n;
    linkedList list = linkedList();
    cout << "Enter the amount of data: ";br;
    cin >> n;
    list.readData(n);
    list.printList();
    list.addAt(10,3);
    list.printList();
    list.deleteAt(4);
    list.printList();

    return 0;
}