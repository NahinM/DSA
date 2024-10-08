#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include "graph.h"
using namespace std;

#define repti(a,b) for(int i=a;i<b;i++)
#define reptj(a,b) for(int j=a;j<b;j++)
#define pii pair<int,int>
#define vpii vector<pii>
#define br cout << '\n'

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