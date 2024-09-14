#include <bits/stdc++.h>
using namespace std;
//implemented by dijkstras algorithm
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> adj[n + 1];
    vector<int> minDist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<int> shortestPath;
    //creating a adjacency list
    for(vector<int> &edge: edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //initail configiration
    minDist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for(pair<int, int> adjPair: adj[node]){
            int adjNode = adjPair.first;
            int adjWeight = adjPair.second;
            int currDist = dist + adjWeight;
            if(currDist < minDist[adjNode]){
                parent[adjNode] = node;
                minDist[adjNode] = currDist;
                pq.push({currDist, adjNode});
            }
        }
    }

    //if we cannot reach node n
    if(parent[n] == -1) return {-1};
    int dest = n;
    while(dest != -1){
        shortestPath.push_back(dest);
        dest = parent[dest];
    }
    //push the weight of the n node
    shortestPath.push_back(minDist[n]);
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

//TC:- O(V+E)logV (same as dijkstras algorithm)
//SC:- O(V+E)