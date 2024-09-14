//url:- "https://www.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1"
//level:- "Medium"
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int findComplement(string &str, unordered_map<int, int> &openToClose)
{
    stack<int> st;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            st.push(i);
        }
        else if (str[i] == ')')
        {
            openToClose[st.top()] = i;
            st.pop();
        }
    }
}

Node *buildTree(string &str, unordered_map<int, int> &openToClose, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    // for handling more than one digit number
    int num = 0;
    while (start <= end && str[start] >= '0' && str[start] <= '9')
    {
        num = num * 10 + str[start] - '0';
        start++;
    }

    Node *root = new Node(num);

    if (start <= end)
    {
        int index = openToClose[start];
        root->left = buildTree(str, openToClose, start + 1, index - 1);
        root->right = buildTree(str, openToClose, index + 2, end - 1);
    }

    return root;
}
// function to construct tree from string
Node *treeFromString(string str)
{
    // map every opening parenthis to int's closing parenthensis
    unordered_map<int, int> openToClose;
    findComplement(str, openToClose);

    return buildTree(str, openToClose, 0, str.length() - 1);
}

void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right); 
}

int main(){
    string str = "4(2(3)(1))(6(5))";
    Node* head = treeFromString(str);
    cout << "Inorder traversal of generated tree from string: " << endl;
    inorder(head);
}

//Time complexity: O(N)
//Space complexity: O(N)