//url:- "https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1"
//level:- "Medium"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data, row, col;
    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
// comparision type function compare
class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a -> data > b -> data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    priority_queue<Node*, vector<Node*>, compare> mh;
    vector<int> ans;
    for(int i = 0; i < k; i++){
        Node* temp = new Node(kArrays[i][0], i, 0);
        mh.push(temp);
    }
    while(!mh.empty()){
        Node* temp = mh.top();
        mh.pop();
        int data = temp->data;
        int i = temp->row;
        int j = temp->col;
        delete temp;
        ans.push_back(data);
        if(j+1 < kArrays[i].size()){
            Node* temp = new Node(kArrays[i][j+1], i, j+1);
            mh.push(temp);
        }
    }
    return ans;
}

int main(){

    vector<vector<int>> kArrays = {
                                    {2}, 
                                    {3, 5, 9},  
                                    {1, 2, 3, 8}
                                  };
    vector<int> ans = mergeKSortedArrays(kArrays, 3);
    cout << "Merged vector is: " << endl;

    for(int v : ans){
        cout<< v <<" ";
    }
    return 0;
}
//Time complexity:- O(n*k log(k))
//Space complexity:- O(n*k)