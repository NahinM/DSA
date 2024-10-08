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


void bfs(Graph graph,int start){
    int visited[graph.nodes()] = {};
    queue<int> Q;
    visited[start] = 1;
    Q.push(start);
    int tem;
    while (!Q.empty())
    {
        tem = Q.front();
        Q.pop();
        for(pii &edg:*graph.connectedEdgs(tem)) if(visited[edg.first] == 0) {
            Q.push(edg.first);
            visited[edg.first] = 1;
        }
        cout << tem << ' ';
    }br;
}

int main(){
    freopen("input.txt","r",stdin);

    int n,e;
    cin >> n >> e;
    Graph graph = Graph(n);
    graph.readData(e); // it reads all ndoe u, node v and weigth of the edge; input: e is number of edges
    graph.printGraph();

    bfs(graph,2);
}