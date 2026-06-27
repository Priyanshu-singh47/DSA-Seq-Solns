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

    ListNode* findkthnode(  ListNode* temp,int k){
        k-=1;
        while(temp!=nullptr && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* temp=head;
          ListNode* prev=nullptr;
           ListNode* nextnode=nullptr;
           while(temp!=nullptr){
             ListNode* kthnode=findkthnode(temp,k);
             if(kthnode==nullptr){
                if(prev){
                    prev->next=temp;
                    break;
                }
             }
             nextnode=kthnode->next;
             kthnode->next=nullptr;
             reverseList(temp);
             if(temp==head){
                head=kthnode;
             }
             else{
                prev->next=kthnode;
             }
             prev=temp;
             temp=nextnode;



           }
           return head;


        
    }
};