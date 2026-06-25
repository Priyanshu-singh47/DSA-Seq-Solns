ListNode* deleteHead(ListNode* &head) {

        if(head == nullptr)
            return nullptr;

        if(head->next == nullptr){
            delete head;
            return nullptr;
        }

        ListNode* temp = head;

        head = head->next;

        head->prev = nullptr;

        temp->next = nullptr;

        delete temp;

        return head;
    }
};
