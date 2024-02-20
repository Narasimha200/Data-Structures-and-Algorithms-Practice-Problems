// url:- "https://leetcode.com/problems/two-sum-iv-input-is-a-bst/"
//  level:- "Medium"
// bruteforce:- try for every node in the tree to every node in the tree solved in n*log(n) time complexity
//and optimal code is writern below
#include <iostream>
#include <vector>
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
// values are stored in sorted order
vector<int> v;

void insert(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    insert(root->left);
    v.push_back(root->val);
    insert(root->right);
}
bool twoSum(TreeNode *root, int k)
{
    insert(root);
    int left = 0, right = v.size() - 1;
    while (left < right)
    {
        int sum = v[left] + v[right];
        if (sum == k)
        {
            return true;
        }
        else if (sum < k)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}

int main()
{
    TreeNode *head = NULL;
    int k = 9;
    bool present = twoSum(head, k);
    if (present == true)
    {
        cout << "Yes pairs are present bst" << endl;
    }
    else
    {
        cout << "NO pairs are not present bst" << endl;
    }
}
// time complexity:- O(N)
// space complexity:- O(N)