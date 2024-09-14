#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>()> minHeap;
    vector<int> minDist(V, 1e9);
    minDist[S] = 0;
    minHeap.push({0, S});

    while (!minHeap.empty())
    {
        int node = minHeap.top().second;
        int dist = minHeap.top().first;

        for(auto &v: adj[node]){
            int adjNode = v[0];
            int adjNodeWeight = v[1];
            if(dist + adjNodeWeight < minDist[adjNode]){
                minDist[adjNode] = dist + adjNodeWeight;
                minHeap.push({minDist[adjNode], adjNode});
            }
        }
    }
    return minDist;
}

//TC:- Elog(V)
//SC:- V^2