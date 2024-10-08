#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

#define repti(a,b) for(int i=a;i<b;i++)
#define reptj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define vpii vector<pii>
#define br cout << '\n'

class Graph
{
private:
    vector<pii> *graph = nullptr;
    int graphNodes = 0;
    bool directed = false;
public:
    Graph(int n, bool drct);
    void addEdge(int u,int v, int w);
    void printGraph();
    vpii* connectedEdgs(int v);
    void readData(int edgs);
    int nodes();
};

int Graph::nodes(){
    return graphNodes;
}

Graph::Graph(int n, bool drct = false){
    graph = new vector<pii>[n];
    graphNodes = n;
    directed = drct;
}

void Graph::addEdge(int u, int v, int w){
    graph[u].push_back(make_pair(v,w));
    if(!directed) graph[v].push_back(make_pair(u,w));
}

void Graph::readData(int edgs){
    int u,v,w;
    while(edgs--){
        cin >> u >> v >> w;
        addEdge(u,v,w);
    }
}

vpii* Graph::connectedEdgs(int v){
    return &graph[v];
}

void Graph::printGraph(){
    repti(0,graphNodes){
        cout << i << " -> ";
        for(pii &edg:graph[i]){
            printf("%d(%d) ",edg.first,edg.second);
        }br;
    }br;
}

void dfs(Graph graph, int start){
    const int n = graph.nodes();
    int visited[n] = {},tem;
    stack<int> stk;
    stk.push(start);
    visited[start] = 1;
    while (!stk.empty())
    {
        tem = stk.top();
        stk.pop();
        for(pii &edg:*graph.connectedEdgs(tem)) if(visited[edg.first] == 0) {
            stk.push(edg.first);
            visited[edg.first] = 1;
        }
        cout << tem << ' ';
    }
    br;
}

int main(){
    freopen("input.txt","r",stdin);

    int n,e;
    cin >> n >> e;
    Graph graph = Graph(n);
    graph.readData(e); // it reads all ndoe u, node v and weigth of the edge; input: e is number of edges
    graph.printGraph();

    dfs(graph,2);
}