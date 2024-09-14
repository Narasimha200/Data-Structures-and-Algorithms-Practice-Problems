#include <iostream>
#include <vector>
using namespace std;

bool dfs(int v, vector<int> *adj, bool path[], bool visited[]){
    visited[v] = path[v] = true;
    for(int ad: adj[v]){
        if(visited[ad] == false){
            if(dfs(ad, adj, path, visited)) return true;
        }
        else if(path[ad] == true){
            return true;
        }
    }
    // while going back remove curr vertice from path
    path[v] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    // code here
    bool path[V] = {0};
    bool visited[V] = {0};
    for(int i = 0; i < V; i++)
        if(!visited[i] && dfs(i, adj, path, visited)) return true;
    return false;
}

int main(){
    vector<int> adj[5];
    isCyclic(5, adj);
}

//TC:-O(V+E)
//Sc:-O(V)