#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int> > &roads)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
    vector<long long> waysUpto(n, 0);
    vector<pair<long long, long long> > adj[n];
    vector<long long> minDist(n, 1e18);
    for (auto v : roads)
    {
        adj[v[0]].push_back({v[1], v[2]});
        adj[v[1]].push_back({v[0], v[2]});
    }
    minDist[0] = 0;
    waysUpto[0] = 1;
    pq.push({0, 0});
    long long mod = 1e9 + 7;
    while (!pq.empty())
    {

        long long node = pq.top().second;
        long long dist = pq.top().first;
        pq.pop();

        for (auto p : adj[node])
        {
            long long adjNode = p.first;
            long long adjWeight = p.second;
            if (adjWeight + dist < minDist[adjNode])
            {
                minDist[adjNode] = (dist + adjWeight) % mod;
                pq.push({minDist[adjNode], adjNode});
                waysUpto[adjNode] = waysUpto[node];
            }
            else if ((adjWeight + dist) % mod == minDist[adjNode])
            {
                waysUpto[adjNode] = (waysUpto[adjNode] + waysUpto[node]) % mod;
            }
        }
    }
    return waysUpto[n - 1];
}

//TC:- same as dijkstras algorithm
//SC:- O(N+M) where N = vertices and M = edges