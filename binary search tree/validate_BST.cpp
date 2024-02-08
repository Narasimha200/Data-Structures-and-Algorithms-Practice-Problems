//url:- "https://leetcode.com/problems/validate-binary-search-tree/"
//level:- "Medium"

#include<iostream>
#include<climits>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

bool isValidBST(TreeNode* root, long mini = -10e10, long maxi = 10e10) {
        if(root == NULL){
            return true;
        }
        if(root->val > mini && root->val < maxi){
            bool left = isValidBST(root->left, mini, root->val);
            bool right = isValidBST(root->right, root->val, maxi);
            return left && right;
        }
        else
            return false;
}

int main(){
    //pass binary tree head
    if(isValidBST(NULL, INT_MIN, INT_MAX)){
        cout<<"It is a binary tree"<<endl;
    }
    else{
        cout<<"No, this is not a binary tree";
    }
    cout<<sizeof(1)<<endl;
    return 0;
}
// time complexity:- O(n)
// space complexity:- O(h)