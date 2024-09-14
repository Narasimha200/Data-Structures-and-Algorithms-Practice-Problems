#include <bits/stdc++.h>
using namespace std;
//remove edges between c and d then check whether we can d can be reach by c or not.
bool isSafe(int node, int adjNode, int c, int d){
    if((node == c && adjNode == d) || (node == d && adjNode == c)) return false;
    return true;
}
void dfs(int node, vector<int> adj[], vector<int> &visited, int c, int d){
    visited[node] = 1;
    for(int adjNode: adj[node]){
        if(isSafe(node, adjNode, c, d) && !visited[adjNode]){
            dfs(adjNode, adj, visited, c, d);
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    // Code here 
    vector<int> visited(V);

    dfs(c, adj, visited, c ,d);

    return !visited[d];
}