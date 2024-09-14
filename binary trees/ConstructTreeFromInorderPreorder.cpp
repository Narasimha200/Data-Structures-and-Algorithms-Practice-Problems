// url:- "https://www.geeksforgeeks.org/problems/construct-tree-1/1"
// level:- "Medium"

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){};
};
int findIndexOfRoot(int in[], int rootElement, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == rootElement)
        {
            return i;
        }
    }
    return -1;
}

Node *build(int in[], int pre[], int &preIndex, int preStart, int preEnd, int n)
{
    if (preStart > preEnd)
    {
        return NULL;
    }
    int rootElement = pre[preIndex++];
    Node *root = new Node(rootElement);
    int posOfRoot = findIndexOfRoot(in, rootElement, preStart, preEnd);
    root->left = build(in, pre, preIndex, preStart, posOfRoot - 1, n);
    root->right = build(in, pre, preIndex, posOfRoot + 1, preEnd, n);
    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    int index = 0;
    return build(in, pre, index, 0, n - 1, n);
}

int main(){
    int inorder[] = {1, 6, 8, 7};
    int preorder[] = {1, 6, 7, 8};
    int n = sizeof(inorder)/ sizeof(inorder[0]);
    Node* root = buildTree(inorder, preorder, n);
}

//Time Complexity: O(N^N)
//Space Complexity:- O(H)