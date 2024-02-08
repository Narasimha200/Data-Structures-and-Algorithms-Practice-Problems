// url:- "https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1"
// Level:- "Easy"
// //brute force is to check every node
// #include<iostream>
// #include<vector>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int data){
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// bool search(Node* root,int val){
//     if(root == NULL){
//         return false;
//     }
//     if(root->data == val){
//         return true;
//     }
//     bool l = search(root->left, val);
//     bool r = search(root->right, val);
//     return l || r;
// }
// Node* insert(Node* root, int data){
//     if(root == NULL){
//         root = new Node(data);
//         return root;
//     }
//     if( data > root->data){
//         root->right = insert(root->right, data);
//     }
//     else{
//         root->left = insert(root->left, data);
//     }
//     return root;
// }
// int main(){
//     vector<int> v={5,1,2,9,3,7,6};
//     // -1 for termination of creating the tree
//     Node* head = NULL;
//     for(int num:v){
//         head = insert(head,num);
//     }
//     cout<<search(head, 9)<<endl;
// }
// time complexity: O(n)
// space complexity: O(H)

// optimised idea is to use the truth that, for every node left subtree only have smaller elements
// and right subtree have larger elements than parent node
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
bool search(Node* root,int val){
    if(root == NULL){
        return false;
    }
    if(root->data == val){
        return true;
    }
    if(root->data > val)
    return search(root->left, val);
    else
    return search(root->right, val);
}
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
    vector<int> v={5,1,2,9,3,7,6};
    // -1 for termination of creating the tree
    Node* head = NULL;
    for(int num:v){
        head = insert(head,num);
    }
    cout<<search(head, 9)<<endl;
}
//time complexity:- O(log(n))
//space complexity:- O(H)