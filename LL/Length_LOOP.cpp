class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode *slow=head;
        ListNode * fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            int cnt=1;
            if(slow==fast){
                ListNode *temp=slow;
               
                slow=slow->next;
                while(slow!=temp){
                    slow=slow->next ;
                    cnt++;
                }
                return cnt;
            }
           
        }
        return 0;

    }
};