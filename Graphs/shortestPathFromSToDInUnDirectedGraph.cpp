#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//finds shortest path from source node to destination node 
vector<int> shortestPath(vector<vector<int>> &grid, int S, int D){
    int V = grid.size();
    queue<int> q;
    bool visited[V] = {0};
    int parent[V] = {0};
    parent[S] = -1;
    visited[S] = true;
    q.push(S);

    while(q.empty() == false){
        int v = q.front();
        q.pop();

        for(int neigh: grid[v]){
            if(visited[neigh] == false){
                visited[neigh] = true;
                parent[neigh] = v;
                q.push(neigh);
            }
        }
    }
    vector<int> path;
    while(D != -1){
        path.push_back(D);
        D = parent[D];
    }
    reverse(path.begin(), path.end());
    return path;
}


int main(){
    vector<vector<int>> grid = {
        {},
        {2, 3, 6},
        {1, 3},
        {1, 8},
        {6, 8},
        {2, 8},
        {1, 4},
        {},
        {}
    };
    vector<int> ans = shortestPath(grid, 1, 8);
    cout << ans.size() << endl;
    for(int v: ans){
        cout << v << " ";
    }
}