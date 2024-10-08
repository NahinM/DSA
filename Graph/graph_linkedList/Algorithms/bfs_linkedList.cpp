#include <iostream>
#include <queue>
#include "graph_linkedList.h"
using namespace std;

void bfs(Graph *graph,int start){
    int visited[(*graph).nodes()] = {};
    queue <int> Q;
    Q.push(start);
    visited[start] = 1;
    int tem;
    Node *at;
    while (!Q.empty())
    {
        tem = Q.front();
        Q.pop();
        at = (*graph).connectedEdgs(tem);
        while(at != nullptr) {
            int d = at->data;
            if(visited[d] == 0 ){
                Q.push(d);
                visited[d] = 1;
            }
            at = at->next;
        }
        
        cout << tem << ' ';
    }br;
    
}

int main(){
    freopen("graphData.txt","r",stdin);
    int n,e;
    cin >> n >> e;
    Graph graph = Graph(n);
    graph.readData(e);
    graph.printGraph();
    bfs(&graph,0);
}