//url:- "https://leetcode.com/problems/merge-k-sorted-lists/description/"
//level:- "Hard"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a -> val > b -> val;
    }
};
ListNode* mergeKLists(vector<ListNode*> &lists) {
    
    priority_queue< ListNode*, vector<ListNode*>, compare > mHeap;

    for(ListNode* node: lists){
        if(node != NULL)
            mHeap.push(node);
    }
    //to maintain a list we need to maintain a head 
    // for inserting at end we need to use tail
    ListNode  *head = NULL, *tail = NULL;
    while(!mHeap.empty()){
        ListNode* tempNode = mHeap.top();
        mHeap.pop();
        if(head == NULL){
            head = tail = tempNode;
        }
        else{
            tail -> next = tempNode;
            tail = tail -> next;
        }
        // check have tempNode next not equal to NULL
        if(tempNode -> next != NULL){
            mHeap.push(tempNode -> next);
        }
    }
    return head;
}

ListNode* makeList(vector<int> &v){
    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;
    for(int i = 1; i < v.size(); i++){
        temp -> next = new ListNode(v[i]);
        temp = temp -> next;
    }
    return head;
}

void printList(ListNode* head){
    while(head){
        cout<< head -> val << " ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
    // to create some linked lists
    vector<int> v1 = {1, 4, 5};
    vector<int> v2 = {1, 3, 4};
    vector<int> v3 = {2, 6};
    ListNode* head1 = makeList(v1);
    ListNode* head2 = makeList(v2);
    ListNode* head3 = makeList(v3);

    vector<ListNode*> nodes = {head1, head2, head3};

    ListNode* mergedHead = mergeKLists(nodes);
    cout<< "Merged Lists: " << endl;
    printList(mergedHead);

}

//Time complexity:- O(n*k log(k))
//Space complexity:- O(k)
//where n is largest size of vector and k is no.of lists