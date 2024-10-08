#include <iostream>
#include <stack>
#include "graph_linkedList.h"
using namespace std;

void dfs(Graph *graph,int start){
    int visited[(*graph).nodes()] = {};
    stack <int> stk;
    stk.push(start);
    visited[start] = 1;
    int tem;
    Node *at;
    while(!stk.empty()){
        tem = stk.top();
        stk.pop();
        at = (*graph).connectedEdgs(tem);
        while(at != nullptr){
            int d = at->data;
            if(visited[d] != 1){
                stk.push(d);
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
    dfs(&graph,0);
}