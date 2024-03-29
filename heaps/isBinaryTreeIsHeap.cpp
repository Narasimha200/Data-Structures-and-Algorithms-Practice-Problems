// url:- "https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1"
// level:- "Medium"

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this -> data = data;
        left = right = NULL;
    }
};

int countNodes(struct Node *tree)
{

    if (tree == NULL)
    {
        return 0;
    }

    return countNodes(tree->left) + countNodes(tree->right) + 1;
}

bool isCbt(struct Node *tree, int index, int size)
{

    if (tree == NULL)
    {
        return true;
    }

    if (index >= size)
    {
        return false;
    }

    bool left = isCbt(tree->left, index * 2 + 1, size);
    bool right = isCbt(tree->right, index * 2 + 2, size);

    return left && right;
}

bool maxOrder(Node *tree)
{

    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
    {
        return true;
    }

    else if (tree->right == NULL)
    {
        return (tree->data >= tree->left->data);
    }

    else
    {
        bool curr = (tree->left->data <= tree->data) && (tree->right->data <= tree->data);
        return curr && maxOrder(tree->left) && maxOrder(tree->right);
    }
}

bool isHeap(struct Node *tree)
{

    return isCbt(tree, 0, countNodes(tree)) && maxOrder(tree);
}

int main(){
    // pass binary tree head
    Node *head = NULL;

    if( isHeap(head) ){
        cout<<"Given binary tree is a heap" << endl;
    }
    else{
        cout<<"Given binary tree is not a heap" << endl;
    }
    return 0;
}

//Time Complexity:- O(N)
//Space complexity:- O(H)