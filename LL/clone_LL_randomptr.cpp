class Solution {
public:
    void insertcopyinbetween(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }
    }
    void connectrandompointers(Node* head){
       Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=temp->next;
            if(temp->random){
            copynode->random=temp->random->next;
            temp=temp->next->next;}
            else {copynode->random=nullptr;
            temp=temp->next->next;}
        }
    }
        Node* deepcopylist(Node* head){
                Node* dnode=new Node(-1);
                Node* res=dnode;
                Node* temp=head;
                while(temp!=nullptr){
                res->next=temp->next;
                temp->next=temp->next->next;
                res=res->next;
                temp=temp->next;
                }

          return dnode->next;
        }
    
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
    return nullptr;
        insertcopyinbetween(head);
        connectrandompointers(head);
        return deepcopylist(head);
        
    }
};