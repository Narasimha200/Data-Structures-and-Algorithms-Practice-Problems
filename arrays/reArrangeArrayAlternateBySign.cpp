#include <bits/stdc++.h>
using namespace std;

// LINK:- https://leetcode.com/problems/rearrange-array-elements-by-sign/

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int posIndex = 0;
    int negIndex = 1;
    for (int ele : nums)
    {
        if (ele > 0)
        {
            ans[posIndex] = ele;
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = ele;
            negIndex += 2;
        }
    }
    return ans;
}
//TC:- O(N)
//SC:- O(N)