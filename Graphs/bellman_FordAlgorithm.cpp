#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{

    // Code here
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    // do one iteration for checking negetive cycle
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] != 1e8 && dist[u] + w < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}

//TC:- O(V * E)
//SC:- O(V)