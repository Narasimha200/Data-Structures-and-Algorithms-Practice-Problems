#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insert(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if( data > root->data){
        root->right = insert(root->right, data);
    }
    else{
        root->left = insert(root->left, data);
    }
    return root;
}
int main(){
    int data;
    cin >> data;
    // -1 for termination of creating the tree
    Node* head = NULL;
    while(data!=-1){
        head = insert(head,data);
        cin >> data;
    }
    return 0;
}