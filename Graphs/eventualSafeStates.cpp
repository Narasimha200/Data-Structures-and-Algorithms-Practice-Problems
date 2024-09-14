#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//------------------------------------------------------
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> reversedAdj[V];
    vector<int> indegree(V);
    vector<int> safeStates;
    queue<int> q;
    //reverse the edges
    for(int node = 0; node < V; node++){
        for(int adjNode: adj[node]){
            reversedAdj[adjNode].push_back(node);
            indegree[node]++;
        }
    }
    //push all the nodes whose indegree is zero in queue
    for(int node = 0; node < V; node++){
        if(indegree[node] == 0) q.push(node);
    }

    //perform the topological sort

    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeStates.push_back(node);
        for(int adjNode: reversedAdj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) q.push(adjNode);
        }
    }

    sort(safeStates.begin(), safeStates.end());
    return safeStates;
}

//TC:- O(Vlog(V)+E)
//SC:- O(V+E)
//------------------------------------------------------------------------------------
void dfs(int src, vector<int> &visited, vector<bool> &safe, vector<vector<int>> &adj){
    visited[src] = 1;
    bool isSafe = true;
    for(int adjNode: adj[src]){
        if(!visited[adjNode]){
            dfs(adjNode, visited, safe, adj);
        }
        isSafe &= safe[adjNode];
    }
    safe[src] = isSafe;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int V = graph.size();
    vector<int> visited(V);
    vector<bool> safe(V);
    vector<int> safeStates;
    //call for difference components
    for(int i = 0; i < V; i++){
        if(!visited[i])
        dfs(i, visited, safe, graph);
    }

    for(int i = 0; i < V; i++){
        if(safe[i]){
            safeStates.push_back(i);
        }
    }
    return safeStates;
}
//TC:- O(V+E)
//SC:- O(V)
//--------------

