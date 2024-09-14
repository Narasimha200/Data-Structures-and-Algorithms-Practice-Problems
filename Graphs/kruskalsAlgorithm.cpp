#include <bits/stdc++.h>
using namespace std;
class disjoinSet
{
    // use either union by rank or union by size not both.
    vector<int> rank, parent, size;

public:
    disjoinSet(int n)
    {
        // for support fo 1based indexing
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findUltiParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        int result = findUltiParent(parent[node]);
        // path compression
        parent[node] = result;
        return result;
    }

    void unionByRank(int u, int v)
    {
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        // both are already in the same component
        if (ultiParent_u == ultiParent_v)
            return;

        if (rank[ultiParent_u] < rank[ultiParent_v])
        {
            parent[ultiParent_u] = ultiParent_v;
        }
        else if (rank[ultiParent_v] < rank[ultiParent_u])
        {
            parent[ultiParent_v] = ultiParent_u;
        }
        else
        {
            parent[ultiParent_v] = ultiParent_u;
            rank[ultiParent_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        // both are already in the same component
        if (ultiParent_u == ultiParent_v)
            return;

        if (size[ultiParent_u] < size[ultiParent_v])
        {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
        else
        {
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
    }
};
int spanningTree(int V, vector<vector<int>> adj[])
{
    //create edges from adjacency list
    vector<pair<int, pair<int, int>>> edges;
    int totalWeight = 0;
    disjoinSet ds(V);
    //(V+E)
    for(int node = 0; node < V; node++){
        for(int it: adj[node]){
            int adjNode = it[0];
            int adjWeight = it[1];
            edges.push_back({adjWeight, {node, adjNode}});
        }
    }
    //ElogE
    sort(edges.begin(), edges.end());
    //E * alpha(V)
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if(ds.findUltiParent(u) != ds.findUltiParent(v)){
            totalWeight += w;
            ds.unionBySize(u, v);
        }
    }
    return totalWeight;
}

//TC:- (ElogE)
//SC:- (E)

