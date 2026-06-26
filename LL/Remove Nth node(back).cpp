class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* temp=head; ListNode* save=nullptr;
         if(head==nullptr) return nullptr;int cnt=0;
         while(temp!=nullptr){
            cnt++;
            temp=temp->next;

         }
         int m=0;
         m=cnt-n;
         if(m==0){
            temp=head;
            head=head->next;
            delete(temp);
            return head;
         }
         temp=head;
         while(temp!=nullptr){
            if(m==1){
                save=temp->next;
                temp->next=temp->next->next;
                save->next=nullptr;
                delete(save);
                break;
            }
            m--;
            temp=temp->next;
         }
        return head;
    }
};

//optimal below

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast becomes nullptr, remove the head
        if (fast == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Move both pointers
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from the end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};
