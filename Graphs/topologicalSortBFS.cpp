// Kahns algorithm
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    queue<int> q;
    vector<int> topologicalSort;
    //find indegrees of all nodes in the graph
    for(int node = 0; node < V; node++){
        for(int adjNode:adj[node])
            indegree[adjNode]++;
    }
    //push all zero indegree nodes into queue
    for(int node = 0; node <V; node++){
        if(indegree[node] == 0) q.push(node);
    }
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topologicalSort.push_back(node);
        for(int adjNode: adj[node]){
            if(--indegree[adjNode] == 0) q.push(adjNode);
        }
    }
    return topologicalSort;
}