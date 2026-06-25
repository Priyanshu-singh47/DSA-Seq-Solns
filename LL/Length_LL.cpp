class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* temp=head;int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;

        }
        return cnt;
    }
};