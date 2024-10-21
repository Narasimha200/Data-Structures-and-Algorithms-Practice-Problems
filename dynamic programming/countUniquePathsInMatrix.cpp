#include <bits/stdc++.h>
using namespace std;
//we are starting from m-1 and n-1 to 0 and 0
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else{
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}
//TC:- O(M * N)
//SC:- O(M * N)

//Space optimized
/* we just accessing the uprow and left columns every time*/
int uniquePaths(int m, int n)
{
    vector<int> upRow(n);
    vector<int> currRow(n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                currRow[j] = 1;
            }
            else{
                int up = 0, left = 0;
                if(i > 0) up = upRow[j];
                if(j > 0) left = currRow[j-1];
                currRow[j] = up + left;
            }
            //equals to upRow = currRow
            upRow[j] = currRow[j]; //optimizing copying like 43 line
        }
        // upRow = currRow; 
    }
    return currRow[n-1];
}

//TC:- O(M * N)
//SC:- O(N)