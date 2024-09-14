#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsTopo(int node, bool visited[], stack<int> &st, vector<int> adj[]){
    visited[node] = true;
    for(int neighbour: adj[node]){
        if(!visited[neighbour]){
            dfsTopo(neighbour, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    bool visited[V] = {0};
    stack<int> st;
    vector<int> ans;
    for(int i = 0; i < V; i++){
        if(!visited[i])
        dfsTopo(i, visited, st, adj);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

//TC:- O(V+E)
//SC:- O(V)