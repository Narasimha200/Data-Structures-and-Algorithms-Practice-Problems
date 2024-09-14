#include <bits/stdc++.h>
using namespace std;
// reference link: https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    disjointSet ds(n * m);
    vector<vector<int>> islands(n, vector<int>(m));
    vector<int> ans;
    int noIslands = 0;
    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, 1, 0, -1};
    for(auto operation: operators){
        int row = operation[0];
        int col = operation[1];
        if(islands[row][col] == 0){
            noIslands++;
        }
        islands[row][col] = 1;

        int label = row * m + col;
        //check for four sides

        for(int i = 0; i < 4; i++){
            int nRow = row + rowDir[i];
            int nCol = col + colDir[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && islands[nRow][nCol] == 1){
                int currLabel = nRow * m + nCol;
                if(ds.findUltiParent(label) != ds.findUltiParent(currLabel)){
                    ds.unionBySize(label, currLabel);
                    noIslands--;
                }
            }
        }
        ans.push_back(noIslands);
    }
    return ans;
}