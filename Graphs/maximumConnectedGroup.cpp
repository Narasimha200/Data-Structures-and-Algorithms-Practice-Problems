#include <iostream>
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

int MaxConnection(vector<vector<int>> &grid)
{
    int n = grid.size();
    disjointSet ds(n * n);
    int maxNoIslands = 0;
    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, 1, 0, -1};

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;
            int nodeNo = row * n + col;
            for (int i = 0; i < 4; i++)
            {
                int nRow = row + rowDir[i];
                int nCol = col + colDir[i];
                int adjNodeNo = nRow * n + nCol;
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1)
                {
                    int adjNodeNo = nRow * n + nCol;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int nodeNo = row * n + col;
            if (grid[row][col] == 1)
            {
                maxNoIslands = max(maxNoIslands, ds.countElements(ds.findUltiParent(nodeNo)));
                continue;
            }
            set<int> st;
            for (int i = 0; i < 4; i++)
            {
                int nRow = row + rowDir[i];
                int nCol = col + colDir[i];
                int adjNodeNo = nRow * n + nCol;
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1)
                {
                    st.insert(ds.findUltiParent(adjNodeNo));
                }
            }
            int currSize = 0;
            for (int compo : st)
            {
                currSize += ds.countElements(compo);
            }
            maxNoIslands = max(maxNoIslands, currSize + 1);
        }
    }
    return maxNoIslands;
}
//TC:- O(N * N)
//SC:- O(N * N)