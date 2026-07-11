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


