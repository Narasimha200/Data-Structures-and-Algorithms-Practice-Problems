#include <bits/stdc++.h>
using namespace std;
//we can solve this problem using floyd warshal algorithm
int findCity(int n, int m, vector<vector<int> > &edges, int distanceThreshold)
{
    vector<vector<int>> distMatrix(n, vector<int>(n, 1e9));
    int ans = 0, minNodes = n;
    for(int node = 0; node < n; node++){
        distMatrix[node][node] = 0;
    }
    for(int edgeIdx = 0; edgeIdx < m; edgeIdx++){
        int u = edges[edgeIdx][0];
        int v = edges[edgeIdx][1];
        int w = edges[edgeIdx][2];
        distMatrix[u][v] = w;
        distMatrix[v][u] = w;
    }
    //find the shortest distance
    for(int via = 0; via < n; via++){
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                int srcToVia = distMatrix[row][via];
                int viaToDes = distMatrix[via][col];
                if(srcToVia != 1e9 && viaToDes != 1e9){
                    distMatrix[row][col] = min(distMatrix[row][col], srcToVia + viaToDes);
                }
            }
        }
    }
    //each node chech how many nodes we can reach to another nodes with in thresholdDist
    for(int row = 0; row < n; row++){
        int count = 0;
        for(int col = 0; col < n; col++){
            if(distMatrix[row][col] <= distanceThreshold) count++;
        }
        if(count <= minNodes){
            ans = row;
            minNodes = count;
        }
    }
    return ans;
}


//TC:- O(n^3)
//SC:- O(n^2)