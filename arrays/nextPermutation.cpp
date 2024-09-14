//url:- "https://leetcode.com/problems/next-permutation/description/?source=submission-ac"
//level:- "Medium"

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return;
    }
    int index1 = -1;
    int index2 = -1;
    int n = nums.size();
    // find break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index1 = i;
            break;
        }
    }
    if (index1 == -1)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        // find next greater element
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[index1])
            {
                index2 = i;
                break;
            }
        }
        swap(nums[index1], nums[index2]);
        reverse(nums.begin() + index1 + 1, nums.end());
    }
}
int main(){
    vector<int> permutation = {1, 2, 3};
    nextPermutation(permutation);
    for(int ele: permutation){
        cout << ele << " ";
    }
    cout << endl;
}

//Time complexity: O(N)
//Space complexity: O(1)