
class Solution {
public:
     ListNode*findslast( ListNode* temp){
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        return temp;
     }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
         ListNode* temp=head;
         int updk=0;int n=0;
         while(temp!=nullptr){
            n++;
            temp=temp->next;

         }
         temp=head;
        updk=k%n;
        while(updk!=0){
            updk--;
             ListNode* s_lastnode=findslast(temp);
              ListNode* save=s_lastnode->next;
              s_lastnode->next=nullptr;
              save->next=head;
              head=save;

        }
        return head;
        
    }
};

//optimal below

class Solution {
public:

    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;

        while (temp != nullptr) {
            if (cnt == k)
                return temp;

            cnt++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* tail = head;
        int len = 1;

        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        k = k % len;

        if (k == 0)
            return head;

        // Make the list circular
        tail->next = head;

        // Find the new last node
        ListNode* newLastNode = findNthNode(head, len - k);

        // New head
        head = newLastNode->next;

        // Break the circle
        newLastNode->next = nullptr;

        return head;
    }

};