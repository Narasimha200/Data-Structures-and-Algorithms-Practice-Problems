#include <bits/stdc++.h>
using namespace std;
//memoization
int maxScore(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    //first day maximum score is maximum of two elements which is not last
    if(day == 0){
        int maxScore = -1;
        for(int i = 0; i < 3; i++){
            if(i != last){
                maxScore = max(maxScore, points[0][i]);
            }
        }
        return maxScore;
    }
    if(dp[day][last] != -1){
        return dp[day][last];
    }
    

    int maxi = -1;
    for(int i = 0; i < 3; i++){
        if(i != last){
            maxi = max(maxi, maxScore(day - 1, i, points, dp) + points[day][i]);
        }
    }
    return dp[day][last] = maxi;
}
//TC:- O(n * 4 * 3)
//SC:- O(n * 4) + O(n)

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //memoization
    //dp[3][4] because for n-1 day there is node last
    // vector<vector<int>> dp(3, vector<int>(4, -1));
    // maxScore(day, lastPerformedTask, points)
    // return maxScore(n-1, 3, points, dp);


    //tabulation
    vector<vector<int>> dp(3, vector<int>(4, 0));
    //for the first day
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));


    for(int day = 1; day < n; day++){

        for(int last = 0; last < 4; last++){

            for(int task = 0; task < 3; task++){

                if(last != task)
                dp[day][last] = max(dp[day][last], dp[day-1][task] + points[day][task]);
            }
        }
    }
    return dp[n-1][3];
}
//TC:- O(n * 4 * 3)
//SC:- O(n * 4)
int main(){
    vector<vector<int>> points = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3},
    };
    cout << ninjaTraining(3, points);
}