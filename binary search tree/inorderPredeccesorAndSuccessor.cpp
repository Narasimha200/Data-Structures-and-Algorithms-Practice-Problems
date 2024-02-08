//url:- "https://www.geeksforgeeks.org/problems/predecessor-and-successor/1"
//level:- "Medium"
// write brute force as, store all elements in an array and return next and prev of target element.
#include<iostream>
#include<vector>
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
void findPre(Node* root, Node* &pre, int data){
    if(root == NULL){
        return;
    }
    if(root->data < data){
        pre = root;
    }
    if(root->data >= data){
        findPre(root->left, pre, data);
    }
    else{
        findPre(root->right, pre, data);
    }
}
void findSuc(Node* root, Node* &suc, int data){
    if(root == NULL){
        return;
    }
    if(root->data > data){
        suc = root;
    }
    if(root->data > data){
        findSuc(root->left, suc, data);
    }
    else{
        findSuc(root->right, suc, data);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int data)
{
    // Your code goes here
    findPre(root, pre, data);
    findSuc(root, suc, data);
}
int main(){
    vector<int> v = {10,5,12,1,7,13};
    Node* head = NULL;
    for(int num:v){
        head = insert(head, num);
    }
    Node *pre = NULL, *suc = NULL;
    findPreSuc(head, pre, suc, 5);
    cout<<"predecessor of node 5 :-"<<pre->data<<endl;
    cout<<"predecessor of node 5 :-"<<suc->data<<endl;
    return 0;
}
// time complexity:- O(H)
// space complexity:- O(H)