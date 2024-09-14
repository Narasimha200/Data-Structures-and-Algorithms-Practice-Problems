#include <vector>
#include <queue>
using namespace std;

int findCheapestPrice(int n, vector<vector<int> > &flights, int src, int dst, int K){
    queue<vector<int>> q;
    vector<int> minCost(n, 1e9);
    vector<pair<int, int> > adj[n];
    for(vector<int>& edge: flights){
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    //{stops, node, cost}
    q.push({0, src, 0});
    minCost[src] = 0;

    while(!q.empty()){

        vector<int> top = q.front();
        q.pop();
        int stop = top[0];
        int node = top[1];
        int cost = top[2];
        if(stop > K) break;
        for(auto adjPair: adj[node]){
            int adjNode = adjPair.first;
            int adjCost = adjPair.second;
            if(cost + adjCost < minCost[adjNode] && stop <= K){
                minCost[adjNode] = cost + adjCost;
                q.push({stop + 1, adjNode, minCost[adjNode]});
            }
        }
    }
    if(minCost[dst] == 1e9) return -1;
    else return minCost[dst];
}
int main(){

}