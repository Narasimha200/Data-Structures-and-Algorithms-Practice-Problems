// URL:- https://www.naukri.com/code360/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;
//------------------Memoization---------------------------------------
int calMinimumCostDp(int idx, int k, vector<int> &height, vector<int> &minCost)
{
    if (idx == 0)
        return 0;
    if (minCost[idx] != -1)
        return minCost[idx];

    int minJump = INT_MAX;

    for (int i = 1; i <= k && idx - i >= 0; i++)
    {
        int jumpCost = calMinimumCostDp(idx - i, k, height, minCost) + abs(height[idx] - height[idx - i]);
        minJump = min(minJump, jumpCost);
    }
    minCost[idx] = minJump;
    return minCost[idx];
}

int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> minCost(n, -1);
    calMinimumCostDp(n - 1, k, height, minCost);
    return minCost[n - 1];
}
// TC:- O(N * k)
// SC:- O(N + N) -> O(N)
//----------------------Tabulation-------------------------

int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> minCost(n, INT_MAX);
    minCost[0] = 0;
    for (int idx = 1; idx < n; idx++)
    {
        for (int i = 1; i <= k && idx - i >= 0; i++)
        {
            int jumpCost = minCost[idx - i] + abs(height[idx] - height[idx - i]);
            minCost[idx] = min(minJump, jumpCost);
        }
    }
    return minCost[n - 1];
}
// TC:- O(N * k)
// SC:- O(N)