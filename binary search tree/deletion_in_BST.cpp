//url:- "https://leetcode.com/problems/delete-node-in-a-bst/"
//level:- "Medium"
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
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == key)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL){
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else{
            TreeNode* temp = root->left;
            // find maximum
            while(temp->right != NULL){
                temp = temp -> right;
            }
            root->val = temp->val;
            root->left = deleteNode(root->left, root->val);
        }
    }
    else if(root->val > key){
        root->left = deleteNode(root->left, key);
    }
    else{
        root->right = deleteNode(root->right, key);
    }
    return root;
}
// Time complexity:- O(H) -> O(N)
// Space complexity:- O(H) -> O(N)