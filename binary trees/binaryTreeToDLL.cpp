//url:- "https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1"
//level:- "Hard"

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){};
};

void treeToDLL(Node *root, Node *&head, Node *&prev)
{

    if (root == NULL)
    {
        return;
    }
    // travel left
    treeToDLL(root->left, head, prev);
    // if head value is null
    if (head == NULL)
    {
        head = root;
        prev = root;
    }
    // append root node to linked list
    else
    {
        prev->right = root;
        root->left = prev;
        prev = prev->right;
    }
    // traverl right
    treeToDLL(root->right, head, prev);
}
// Function to convert binary tree to doubly linked list and return it.
Node *bToDLL(Node *root)
{
    // your code here
    Node *head = NULL;
    Node *prev = NULL;
    treeToDLL(root, head, prev);
    return head;
}

int main(){
    Node* root = new Node(1);
    // DLL head
    Node* head = bToDLL(root);
}

//Time complexity:- O(N)
//Space Complexity:- O(H)