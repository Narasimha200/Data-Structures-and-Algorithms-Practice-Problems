#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//using dfs
// bool dfs(int v, vector<int> *adj, bool path[], bool visited[]){
//         visited[v] = path[v] = true;
//         for(int ad: adj[v]){
//             if(visited[ad] == false){
//                 if(dfs(ad, adj, path, visited)) return true;
//             }
//             else if(path[ad] == true){
//                 return true;
//             }
//         }
//         path[v] = false;
//         return false;
// }

// bool isCyclic(int V, vector<int> adj[]) {
//     // code here
//     bool path[V] = {0};
//     bool visited[V] = {0};
//     for(int i = 0; i < V; i++){
//         if(visited[i] == false)
//           if(dfs(i, adj, path, visited)) return true;
//     }
//     return false;
// }

/* USING BFS*/
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    int inDegree[V] = {0};
    int count = 0;
    queue<int> q;
    //calculate the inDegree of all nodes
    for(int i = 0; i < V; i++){
        for(auto v: adj[i]){
            inDegree[v]++;
        }
    }
    //push all nodes whose in degree is zero
    for(int i = 0; i < V; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int neighbour: adj[v]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
        count++;
    }
    //where V is the total number of vertices 
    return count != V;
}

int main(){

}
//TC:- O(V + E)
//SC:- O(V)