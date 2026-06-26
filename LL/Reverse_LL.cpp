class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode* prev=nullptr;
     ListNode* temp=head;
     while(temp!=nullptr){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

     }   
        return prev;
    }
};
 
//optimal below


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode* prev=nullptr;
     ListNode* temp=head;
     while(temp!=nullptr){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

     }   
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
          ListNode* newhead=reverseList(slow->next);
          ListNode* first=head;
            ListNode* second=newhead;
            while(second!=nullptr){
                if(first->val!=second->val){
                    reverseList(newhead);
                    return false;
                }
                first=first->next;
                second=second->next;
            }
            reverseList(newhead);
            return true;

        
        
    }
};