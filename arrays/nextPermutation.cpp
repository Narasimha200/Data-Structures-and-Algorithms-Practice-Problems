// url:- "https://leetcode.com/problems/next-permutation/"
// level:- "Medium"

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int breakPoint = nums.size() - 2;
    while (breakPoint >= 0 && nums[breakPoint] >= nums[breakPoint + 1])
        breakPoint--;
    reverse(nums.begin() + breakPoint + 1, nums.end());
    if (breakPoint >= 0)
    {
        // find next greter element
        for (int i = breakPoint + 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[breakPoint])
            {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }
    }
}
int main()
{
    vector<int> permutation = {1, 2, 3};
    nextPermutation(permutation);
    for (int ele : permutation)
    {
        cout << ele << " ";
    }
    cout << endl;
}

// Time complexity: O(N)
// Space complexity: O(1)