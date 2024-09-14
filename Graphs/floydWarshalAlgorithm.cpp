#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int via = 0; via < n; via++){
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][via] != -1 && matrix[via][col] != -1){
                    matrix[row][col] = min(matrix[row][col], matrix[row][via] + matrix[via][col]);
                }
            }
        }
    }
    //for detecting cycle
    for(int node = 0; node < n; node++){
        if(matrix[node][node] < -1) { /*return as cycle found*/ }
    }
}    