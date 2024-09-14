#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    int height;
    Node(int data){
        this -> data = data;
        this -> height = 1;
        this -> left = NULL;
        this -> right = NULL;
    }
};

int height(Node* node){
    if(node == NULL) return 0;
    return node -> height;
}

inline int getBalanceFactor(Node* node){
    return height(node -> left) - height(node -> right);
}

Node* rightRotate(Node* top){
    Node* mid = top -> left;
    top -> left = mid -> right;
    mid -> right = top;

    top -> height = max(height(top -> left), height(top -> right)) + 1;
    mid -> height = max(height(mid -> left), height(mid -> right)) + 1;

    return mid;
}

Node* leftRotate(Node* top){
    Node* mid = top -> right;
    top -> right = mid -> left;
    mid -> left = top;

    top -> height = max(height(top -> left), height(top -> right)) + 1;
    mid -> height = max(height(mid -> left), height(mid -> right)) + 1;

    return mid;
}

Node *insert(Node* root, int value){
    if(root == NULL){
        return new Node(value);
    }

    if(value < root -> data){
        root -> left = insert(root -> left, value);
    }
    else if(value  > root -> data){
        root -> right = insert(root -> right, value);
    }
    else return root; // as equal values are not allowed in the bst

    root -> height = max(height(root -> left), height(root -> right)) + 1;

    int balanceFactor = getBalanceFactor(root);

    //for left cases
    if(balanceFactor > 1){
        //for left-left case
        if(value < root -> left -> data){
            return rightRotate(root);
        }
        //for left-right case
        else{
            root -> left = leftRotate(root -> left);
            return rightRotate(root);
        }
    }

    if(balanceFactor < -1){
        //for right-right case
        if(value > root -> right -> data){
            return leftRotate(root);
        }
        //for right-left case
        else{
            root -> right = rightRotate(root -> right);
            return leftRotate(root);
        }
    }
    return root;
}

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}

int main(){
    Node* root = NULL;
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);
    preOrder(root);
}

//TC:- O(log(n)) for one insertion
//SC:- O(log(n))