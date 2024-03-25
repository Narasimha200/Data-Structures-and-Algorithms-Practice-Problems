//Url:- "https://www.geeksforgeeks.org/problems/merge-two-bst-s/1"
//Level:- "Hard"

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
void merge(vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
    int i = 0, j = 0, k = 0;
    int size1 = v1.size();
    int size2 = v2.size();
    while (i < size1 && j < size2)
    {
        if (v1[i] <= v2[j])
        {
            v3.push_back(v1[i++]);
        }
        else
        {
            v3.push_back(v2[j++]);
        }
    }
    while (i < size1)
    {
        v3.push_back(v1[i++]);
    }
    while (j < size2)
    {
        v3.push_back(v2[j++]);
    }
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    inorder(root1, v1);
    inorder(root2, v2);
    merge(v1, v2, v3);
    return v3;
}
int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    vector<int> ans = merge(root1, root2);
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}
//Time complexity:- O(N+M)
//Space complexity:- O(N+M)