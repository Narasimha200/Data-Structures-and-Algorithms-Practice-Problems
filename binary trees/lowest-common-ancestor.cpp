//url:- "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/"
// level:- "medium"
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

bool solve(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&lca)
{
    if (root == NULL)
    {
        return false;
    }
    bool left = solve(root->left, p, q, lca);
    bool right = solve(root->right, p, q, lca);
    if ((left && right) || ((left || right) && (root == p || root == q)))
    {
        lca = root;
    }
    return left || right || (root == p || root == q);
}

int lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *lca = NULL;
    solve(root, p, q, lca);
    return lca->val;
}

int main(){
    TreeNode *head = NULL;
    TreeNode *p = NULL;
    TreeNode *q = NULL;
    cout<<lowestCommonAncestor(head, p, q);
}
// time complexity:- O(N)
// space complexity:- O(H)