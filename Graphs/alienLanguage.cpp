#include <vector>
#include <queue>
#include <string>
using namespace std;

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    vector<int> indegree;
    for(int i = 0; i < N-1; i++){
        int j = 0;
        while(j < dict[i].size() && j < dict[i+1].size()){
            if(dict[i][j] != dict[i+1][j]){
                adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
                break;
            }
            j++;
        }
    }

    vector<int> indegree(K, 0);
    queue<int> q;
    string topologicalSort;
    //find indegrees of all nodes in the graph
    for(int node = 0; node < K; node++){
        for(int adjNode:adj[node])
            indegree[adjNode]++;
    }
    //push all zero indegree nodes into queue
    for(int node = 0; node < K; node++){
        if(indegree[node] == 0) q.push(node);
    }
    topologicalSort.operator+=("hello");
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topologicalSort.push_back(node + 'a');
        for(int adjNode: adj[node]){
            if(--indegree[adjNode] == 0) q.push(adjNode);
        }
    }
    return topologicalSort;
}

int main(){}