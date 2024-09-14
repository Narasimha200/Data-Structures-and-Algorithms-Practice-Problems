#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V);
    int sum = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if(visited[node] == true) continue;

        visited[node] = true;
        sum += weight;
        //add the node to mst here if needed

        for(auto it: adj[node]){
            int adjNode = it[0];
            int adjWeight = it[1];
            if(!visited[adjNode]){
                pq.push({adjWeight, adjNode});
            }
        }
    }
    return sum;
}

//TC:- (V + E)logV ===> (ElogV) because for a connected graph E>=v-1
//SC:- O(V)