// url:- "https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1169989605/"
// level:- "Medium"

#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int fastKthSmallest(Node *root, int k, int &count)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = fastKthSmallest(root->left, k, count);
    int num = count;
    count++;
    if (num == k)
    {
        return root->data;
    }
    int right = fastKthSmallest(root->right, k, count);
    return (left > right) ? left : right;
}
int kthSmallest(Node *root, int k)
{
    int count = 1;
    return fastKthSmallest(root, k, count);
}

int main()
{
    //pass bst head to function
    Node* head = NULL;
    //kth smallest element
    int k = 2;
    cout<<"Kth smallest element in BST :- "<<kthSmallest(head, k);
}
// time complexity:- O(N)
// space complexity:- O(H)