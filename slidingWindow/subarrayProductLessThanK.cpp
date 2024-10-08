
// LINK:- "https://leetcode.com/problems/subarray-product-less-than-k/description/"


//sliding window
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 1)
        return 0;
    int product = 1;
    int start = 0;
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        product = product * nums[i];
        while (product >= k)
        {
            product = product / nums[start];
            start++;
        }
        count += i - start + 1;
    }
    return count;
}

//TC:- O(N)
//sC:- O(1)