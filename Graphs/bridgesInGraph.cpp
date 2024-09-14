#include <bits/stdc++.h>
using namespace std;

// Tarjan's time in and low algorithm

int timer = 1;

void dfs(int node, int parent, vector<int> adj, 
        vector<int>&tin, vector<int>&low, vector<int>&visited, vector<vector<int>>&bridges){
    visited[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(int adjNode: adj[node]){
        if(adjNode == parent) continue;
        else if(!visited[adjNode]){
            dfs(adjNode, node, adj, tin, low, visited, bridges);
            low[node] = min(low[node], low[adjNode]);
            //checking bridge
            if(low[adjNode] > tin[node]){
                bridges.push_back({adjNode, node});
            }
        }
        else{
            low[node] = min(low[node], low[adjNode]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    vector<int> tin(n), low(n), visited(n);
    vector<vector<int>> bridges;
    //creating adjacency list

    for(auto edge: connections){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    dfs(0, -1, adj, tin, low, visited, bridges);

    return bridges;
}

//TC:- O(V+E)
//SC:- O(V+E)