#include <string>
#include <vector>
#include <queue>
using namespace std;
//unweighted graph
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    vector<int> minDist(N, -1);
    vector<int> visited(N, 0);
    queue<int> q;
    minDist[src] = 0;
    q.push(src);
    visited[src] = 1;
    //creating an adjacency list
    for(int i = 0; i < M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int adjNode: adj[node]){
            if(!visited[adjNode]){
                q.push(adjNode);
                minDist[adjNode] = minDist[node] + 1;
                visited[adjNode] = 1;
            }
        }
    }

    return minDist;
}

//TC:- O(N + M)
//SC:- O(N + M)