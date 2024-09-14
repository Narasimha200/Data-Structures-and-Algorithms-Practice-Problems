#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st){
    visited[node] = 1;
    for(int adjNode: adj[node]){
        if(!visited[adjNode]){
            dfs(adjNode, adj, visited);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<vector<int>> &reverseAdj, vector<int> &visited){
    visited[node] = 1;
    for(int adjNode: adj[node]){
        if(!visited[adjNode]){
            dfs3(adjNode, adj, visited);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> reverseAdj(V);
    vector<int> visited(V);
    stack<int> st;
    int sccCount = 0;
    //sorting the nodes on their finish time
    for(int node = 0; node < V; node++){
        if(!visited[node]){
            dfs(node, adj, visited, st);
        }
    }
    //reverse the graph
    for(int node = 0; node < V; node++){
        //to reuse visited to call for dfs
        visited[node] = 0;
        for(int adjNode: adj[node]){
            reverseAdj[adjNode].push_back(node);
        }
    }
    //call for an dfs on order of finish time
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!visited[node]){
            sccCount++;
            dfs2(node, reverseAdj, visited);
        }
    }
    return sccCount;
}

//TC:- (V + E)
//SC:- (V + E)