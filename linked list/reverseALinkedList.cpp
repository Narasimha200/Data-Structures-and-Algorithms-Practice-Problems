//url:- "https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article"
//level:- "Easy"

#include <iostream>
using namespace std;

// structure of List Node
class Node{
    public:
    int data;
    Node* next;
    Node(int val):data(val), next(NULL){}
};

Node* reverseList(Node *head)
{
    Node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    //linked list head
    Node* head = NULL;
    //reversed list
    Node* rev = reverseList(head);
}
//Time complexity:- O(n)
//Space complexity:- O(1)