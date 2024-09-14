//url:- "https://www.geeksforgeeks.org/problems/inorder-traversal/1"
//level:- "Medium"
#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int data) : data(data), left(NULL), right(NULL){};
};

void inOrder(Node *root)
{
    // Your code here
    Node *currNode = root;

    while (currNode != NULL)
    {

        if (currNode->left == NULL)
        {
            cout << currNode->data << " ";
            currNode = currNode->right;
        }
        else
        {
            // find inorder predecessor of currNode
            Node *temp = currNode->left;

            while (temp->right != NULL && temp->right != currNode)
            {
                temp = temp->right;
            }

            if (temp->right == NULL)
            {
                temp->right = currNode;
                currNode = currNode->left;
            }
            else
            {
                cout << currNode->data << " ";
                // remove added link
                temp->right = NULL;
                currNode = currNode->right;
            }
        }
    }
}
Node* createList(){
    Node* head = new Node(1);
    head -> left = new Node(2);
    head -> right = new Node(3);
    head -> left -> left = new Node(4);
    head -> left -> right = new Node(5);
    return head;
}
int main(){
    Node *head = createList();
    cout<<"Inorder traversal of binary tree: " << endl;
    inOrder(head);
}

//Time complexity:- O(N)
//Space complexity:- O(1)