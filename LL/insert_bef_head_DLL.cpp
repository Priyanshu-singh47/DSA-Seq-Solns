class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newnode=new ListNode(X,nullptr,head);
        head->prev=newnode;
        return newnode;
    } 
};