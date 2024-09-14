// url:- "https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1"
// level:- "Easy"
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){};
};
int sumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // find left sub tree sum
    int leftSum = sumOfNodes(root->left);
    // find righ sub tree sum
    int rightSum = sumOfNodes(root->right);
    // store original data
    int data = root->data;
    //update root data as left+right sub trees sum
    root->data = leftSum + rightSum;

    return leftSum + rightSum + data;
}

void toSumTree(Node *node)
{
    // Your code here
    sumOfNodes(node);
}
int main(){
    Node* root = new Node(10);
    toSumTree(root); // now tree is converted to sum tree
}
//Time Complexity:- O(N)
//Space Complexity:- O(N)