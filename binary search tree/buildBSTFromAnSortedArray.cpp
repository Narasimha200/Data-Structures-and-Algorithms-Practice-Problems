//url:- "https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/"
//level:- "Easy"

#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};

TreeNode *divideAndConquer(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int midIndex = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[midIndex]);
    root->left = divideAndConquer(nums, start, midIndex - 1);
    root->right = divideAndConquer(nums, midIndex + 1, end);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return divideAndConquer(nums, 0, nums.size() - 1);
}

int main(){
    // pass vector of sorted elements
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    sortedArrayToBST(v);
}
// Time complexity:- O(N)
// Space complexity:- O(N)