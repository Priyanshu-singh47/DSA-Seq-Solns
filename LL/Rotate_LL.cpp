
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

