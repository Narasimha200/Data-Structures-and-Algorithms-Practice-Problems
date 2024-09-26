#include <bits/stdc++.h>
using namespace std;
//URL:- "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/"
int findMin(vector<int> &nums)
{
    int n = nums.size();
    int left = 0, right = n - 1; 
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[n - 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return nums[left];
}

int main(){
    vector<int> v = {4,5,6,7,0,1,2};
    cout << findMin(v) << endl;
}
//TC:- O(logN)
//SC:- O(1)