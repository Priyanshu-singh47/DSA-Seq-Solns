class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {

        ListNode* current = head;
        ListNode* temp = nullptr;

        while(current){

            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if(temp != nullptr)
            head = temp->prev;

        return head;
    }
};