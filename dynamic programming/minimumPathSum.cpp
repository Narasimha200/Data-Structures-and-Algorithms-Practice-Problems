#include <bits/stdc++.h>
using namespace std;
//starting from bottom-right

//memoization
int findMinPathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    //if destination reached
    if(i < 0 || j < 0){
        return 0;
    }
    if(i == 0 && j == 0){
        return grid[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //if out of boundary
    int up = 0, left = 0;
    if(i > 0)
    up = findMinPathSum(i - 1, j, grid, dp);
    if(j > 0)
    left = findMinPathSum(i, j -1, grid, dp);

    return dp[i][j] = grid[i][j] + min(up, left)
}

int minPathSum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return findMinPathSum(m-1, n-1, grid, dp);
}
//TC:- O(M * N)
//SC:- O(M * N)

//Tabulation
int minPathSum(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    // vector<vector<int>> dp(m, vector<int>(n, 0));
    //space optimization
    vector<int> prevRow(n, 0);
    vector<int> currRow(n, 0);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                currRow[j] = grid[i][j];
            }
            else{
                int up = INT_MAX, left = INT_MAX;

                if(i > 0) up = prevRow[j];
                if(j > 0) left = currRow[j-1];

                currRow[j] = grid[i][j] + min(up, left);
            }
        }
        prevRow = currRow;
    }
    return prevRow[n-1];
}

//TC:- O(M * N)
//SC:- O(N)
