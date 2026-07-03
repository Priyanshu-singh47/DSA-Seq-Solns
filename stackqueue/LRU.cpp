class LRUCache {
public:

    class Node{
    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()){

            Node* node = mp[key];
            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
        }
        else{

            if(mp.size() == cap){

                Node* lru = tail->prev;

                deleteNode(lru);
                mp.erase(lru->key);

                delete lru;
            }

            Node* newNode = new Node(key, value);

            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};