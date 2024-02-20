// url:- "https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/"
// level:- "Medium"

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

TreeNode *constructFromPreorder(vector<int> &preorder, int &index, int start = 0, int end = 1001)
{
    if (index >= preorder.size() || preorder[index] < start || preorder[index] > end)
    {
        return NULL;
        int value = preorder[index];
        TreeNode *root = new TreeNode(value);
        index++;
        root->left = constructFromPreorder(preorder, index, start, value);
        root->right = constructFromPreorder(preorder, index, value, end);
        return root;
    }
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    return constructFromPreorder(preorder, index);
}

int main()
{
    // pass vector of preorder elements
    vector<int> v = {8,5,1,7,10,12};
    TreeNode* head = bstFromPreorder(v);
}
// Time complexity:- O(N)
// Space complexity:- O(H)