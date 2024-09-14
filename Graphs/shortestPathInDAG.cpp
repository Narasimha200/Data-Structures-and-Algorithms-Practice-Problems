#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void dfsTopo(int node, bool visited[], stack<int> &st, vector<vector<pair<int,int>>> &adj){
    visited[node] = true;
    for(pair<int,int> &neighbour: adj[node]){
        if(!visited[neighbour.first]){
            dfsTopo(neighbour.first, visited, st, adj);
        }
    }
    st.push(node);
}

void topologicalSort(int N, vector<vector<pair<int,int>>> &adj, stack<int> &st) 
{
    bool visited[N] = {0};
    for(int i = 0; i < N; i++){
        if(!visited[i])
        dfsTopo(i, visited, st, adj);
    }
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<vector<pair<int,int>>> adj(N);
    stack<int> topo;
    vector<int> dist(N, -1);
    // create an adjacentry list
    for(vector<int> &edge: edges){
        int s = edge[0];
        int d = edge[1];
        int w = edge[2];
        adj[s].push_back(make_pair(d, w));
    }

    topologicalSort(N, adj, topo);
    dist[0] = 0;

    while(topo.empty() == false){
        int v = topo.top();
        topo.pop();
        if(dist[v] != -1){
            for(pair<int,int> &des: adj[v]){
                if(dist[des.first] == -1){
                    dist[des.first] = dist[v] + des.second;
                }
                else{
                    dist[des.first] = min(dist[des.first], dist[v] + des.second);
                }
            }
        }
    }
    return dist;
}

int main()
{
}

//TC:- O(V+E)
//SC:- O(V+E)
