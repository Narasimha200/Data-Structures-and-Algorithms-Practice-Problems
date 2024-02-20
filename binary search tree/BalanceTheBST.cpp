//url:- "https://leetcode.com/problems/balance-a-binary-search-tree/"
//medium:- "Medium"

#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
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

void createInorderVector(TreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    createInorderVector(root->left, inorder);
    inorder.push_back(root->val);
    createInorderVector(root->right, inorder);
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> inorder;
    createInorderVector(root, inorder);
    return divideAndConquer(inorder, 0, inorder.size() - 1);
}

int main()
{
    // pass unbalanced bst to balaceBst function
    TreeNode *head = NULL;
    balanceBST(head);
}
// Time complexity:- O(N)
// Space complexity:- O(N)