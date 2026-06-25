class Solution {
public:
    bool searchKey(ListNode* head, int key) {
       ListNode* temp= head;
       while(temp){
        if(temp->val==key) return true;
        temp=temp->next;
       }
       return false;
    }
};