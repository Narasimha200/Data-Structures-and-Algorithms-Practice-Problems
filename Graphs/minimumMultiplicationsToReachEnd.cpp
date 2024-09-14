#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    if(start == end) return 0;
    queue<pair<int, int>> q;
    vector<int> visited(1e5, 0);
    q.push({start, 0});

    while(!q.empty()){
        int node = q.front().first;
        int step = q.front().second;
        q.pop();
        for(int adjNode: arr){
            int res = (node * adjNode) % 1e5;
            if(res == end) return step + 1;
            if(!visited[res]){
                visited[res] = true;
                q.push({res, step + 1});
            }
        }
    }
    return -1;

}
//TC:- (1e5 * 1e4) very hypothetical it may be very less
//SC:- (1e5)