#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    //creating a adjacency list as prerequisite -> currTask edge should be like this
    vector<int> adj[N];
    queue<int> q;
    vector<int> indegree(N);
    int count = 0;
    for(int i = 0; i < P; i++){
        int srcNode = prerequisites[i].second;
        int destNode = prerequisites[i].first;
        adj[srcNode].push_back(destNode);
        indegree[destNode]++;
    }
    //push all the nodes into the queue which have zero indegree
    for(int node = 0; node < N; node++){
        if(indegree[node] == 0) q.push(node);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(int adjNode: adj[node]){
            if(--indegree[adjNode] == 0) q.push(adjNode);
            cout << indegree[adjNode] << endl;
        }
    }

    if(count == N) return true;
    else return false;
}

int main(){
    vector<pair<int, int>> p = {
        // {0, 0},
        {1, 2},
        {2, 1},
    };
    isPossible(3, 2, p);
}

//TC:- O(V+E)
//SC:- O(V+E)