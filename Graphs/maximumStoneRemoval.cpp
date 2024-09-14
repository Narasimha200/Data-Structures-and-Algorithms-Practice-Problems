#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    // use either union by rank or union by size not
    vector<int> rank, parent, size;

public:
    disjointSet(int n)
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
    int countElements(int node)
    {
        return size[node];
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

int maxRemove(vector<vector<int>> &stones, int n)
{
    int maxRow = 0;
    int maxCol = 0;
    for(auto it: stones){
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    disjointSet ds(maxRow + maxCol + 1);
    //to maintain which stones are given
    unordered_set<int> st;
    for(auto it: stones){
        int row = it[0];
        int col = it[1] + maxRow + 1;
        ds.unionBySize(row, col); 
        st.insert({row, col});
    }

    int components = 0;
    for(int node: st){
        if(ds.countElements(node) > 1 && ds.findUltiParent(node) == node) components++;
    }
    return n - components;
}

//TC:- O(N)
//SC:- O(2* (max row index + max column index))
