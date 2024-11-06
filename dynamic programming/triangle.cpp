#include <bits/stdc++.h>
using namespace std;
//Tabulation with space optimization
int minimumTotal(vector<vector<int>> &triangle){
    int n = triangle.size();
    vector<int> dp(n);

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(i == n-1){
                dp[i][j] = triangle[i][j];
            }
            else{
                //change current row directly(with using prevRow)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
    }
    return dp[0];
}

//TC:- O(sum(1 to N))
//SC:- O(N)