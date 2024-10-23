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
    int listSize = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    void push(int d);
    void addAt(int d,int at);
    void deleteAt(int at);
    int size();
    bool isEmpty();
    void readData(int n);
    void reverseList();
    linkedList sortList();
    void printList();
    Node* getHead(){return head;}
    void sort_push(int d);
};


int linkedList::size(){
    return listSize;
}

bool linkedList::isEmpty(){
    return head==nullptr;
}

void linkedList::push(int d){
    // head is address
    // *head is the data at that address
    
    listSize++;
    if(head == nullptr) {
        head = new Node(d);
        tail = head;
        return;
    }

    tail->next = new Node(d);
    tail = tail->next;
}

void linkedList::sort_push(int d){
    if(head == nullptr){
        head = new Node(d);
        return;
    }
    Node *tem = head,*prev = nullptr;
    while(tem != nullptr && tem->data < d){
        prev = tem;
        tem = tem->next;
    }
    if(prev != nullptr) {
        prev->next = new Node(d);
        prev->next->next = tem;
    }else{
        head = new Node(d);
        head->next = tem;
    }
}

void linkedList::addAt(int d,int at){
    if(at < 0 || at>listSize ){
        cout << "invalid index\n";
        return;
    }
    listSize++;
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
    if(at < 0 || at >= listSize){
        cout << "invalid index\n";
        return;
    }
    if(listSize == 0 || head == nullptr){
        cout << "There is no data to delete\n";
        return;
    }
    listSize--;
    Node *tem = head,*terget;
    if(at == 0){
        head = tem->next;
        delete tem;
    }
    if (at == listSize){
        repti(0,at-1)tem = tem->next;
        delete tem->next;
        tem->next = nullptr;
        tail = tem;
        return;
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

void linkedList::reverseList(){
    Node *at=head,*pre=nullptr,*nxt = head;

    while (nxt != nullptr)
    {
        nxt = nxt->next;
        at->next = pre;
        pre = at;
        at = nxt;
    }
    head = pre;
}

linkedList linkedList::sortList(){
    linkedList sortedList = linkedList();
    Node *tem = head;
    while (tem != nullptr)
    {
        sortedList.sort_push(tem->data);
        tem = tem->next;
    }
    return sortedList;
}

int main(){
    freopen("listData.txt","r",stdin);

    int n;
    linkedList list = linkedList();
    cout << "Enter the amount of data: ";br;
    cin >> n;
    list.readData(n);
    list.printList();
    list.addAt(10,3);
    list.printList();
    list.deleteAt(5);
    list.printList();
    list.push(15);
    list.printList();
    list.reverseList();
    list.printList();
    linkedList list2 = list.sortList();
    list2.printList();

    return 0;
}
