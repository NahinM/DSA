#include <iostream>
using namespace std;

#define br cout << '\n'
#define repti(a,b) for(int i=a;i<b;i++)

class Node
{
public:
    int data;
    int weight;
    Node *next = nullptr;
    Node(int d,int w){
        data = d;
        weight = w;
    }
};

class LinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int listSize = 0;
public:
    void push(int d,int w);
    Node* getList();
    int size();
};

Node* LinkedList::getList(){
    return head;
}

int LinkedList::size(){
    return listSize;
}

void LinkedList::push(int d,int w){
    listSize++;
    if(head==nullptr){
        head = new Node(d,w);
        tail = head;
        return;
    }
    tail->next = new Node(d,w);
    tail = tail->next;
}

class Graph
{
private:
    int graphNode = 0;
    LinkedList *graph = nullptr;
    bool directed = false;

public:
    Graph(int n, bool drct);
    void addEdge(int u,int v,int w);
    void printGraph();
    void readData(int e);
};

Graph::Graph(int n, bool drct = false){
    graphNode = n;
    graph = new LinkedList[n];
    directed = drct;
}

void Graph::addEdge(int u,int v,int w){
    graph[u].push(v,w);
    if(!directed) graph[v].push(u,w);
}

void Graph::readData(int e){
    int u,v,w;
    while(e--){
        cin >> u >> v >> w;
        addEdge(u,v,w);
    }
}

void Graph::printGraph(){
    Node *tem = nullptr;
    repti(0,graphNode){
        cout << i << " -> ";
        tem = graph[i].getList();
        while (tem != nullptr)
        {
            printf("%d(%d) ",tem->data,tem->weight);
            tem = tem->next;
        }
        br;
    }br;
}

int main(){
    freopen("input.txt","r",stdin);

    int n,e;
    cin >> n >> e;
    Graph graph = Graph(n);
    graph.readData(e);
    graph.printGraph();
}