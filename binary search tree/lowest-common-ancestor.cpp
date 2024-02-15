// url:- "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/"
//  level:- "Medium"
#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    int small = min(p->val, q->val);
    int large = max(p->val, q->val);
    if (large < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (small > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

int main()
{
    TreeNode *head = NULL;
    TreeNode *p = NULL;
    TreeNode *q = NULL;
    cout << lowestCommonAncestor(head, p, q) -> val <<endl;
}
// time complexity:- O(log(N))
// space complexity:- O(H)