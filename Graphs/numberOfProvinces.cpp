#include <bits/stdc++.h>
using namespace std;
class disjointSet{
    //use either union by rank or union by size not
    vector<int> rank, parent, size;
    public:
    disjointSet(int n){
        //for support fo 1based indexing
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findUltiParent(int node){
        if(node == parent[node]){
            return node;
        }
        int result = findUltiParent(parent[node]);
        //path compression
        parent[node] = result;
        return result;
    }

    void unionByRank(int u, int v){
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        //both are already in the same component
        if(ultiParent_u == ultiParent_v) return;

        if(rank[ultiParent_u] < rank[ultiParent_v]){
            parent[ultiParent_u] = ultiParent_v;
        }
        else if(rank[ultiParent_v] < rank[ultiParent_u]){
            parent[ultiParent_v] = ultiParent_u;
        }
        else{
            parent[ultiParent_v] = ultiParent_u;
            rank[ultiParent_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        //both are already in the same component
        if(ultiParent_u == ultiParent_v) return;

        if(size[ultiParent_u] < size[ultiParent_v]){
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
        else{
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
    }
};

int numProvinces(vector<vector<int>> adj, int V)
{
    disjointSet ds(V);
    int provinces = V;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(adj[i][j] == 1 && ds.findUltiParent(i) != ds.findUltiParent(j)){
                provinces--;                                                                                                                                                                                                                                                             
                ds.unionBySize(i, j);
            }
        }
    }
    return provinces;
}

//TC:- O(V^2)
//SC:- O(V)