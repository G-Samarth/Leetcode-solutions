class LRUCache {
    struct Node{
        int key, val;
        Node* prev;
        Node* next;

        Node(int key, int val) : key(key), val(val), next(NULL), prev(NULL) {}
    };
public:
    int cap = 0;
    unordered_map<int, Node*> address;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    void addToHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        temp->prev = node;

        node->prev = head;
        node->next = temp;
    }

    void removeFromTail(Node* node){
        Node* temp = node->prev;
        temp->next = node->next;
        node->next->prev = temp;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(address.count(key)){
            Node* node = address[key];
            removeFromTail(node);
            addToHead(node);
            return node->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(address.count(key)){
            Node* node = address[key];
            removeFromTail(node);
            addToHead(node);
            node->val = value;
            return;
        }

        if(cap == 0){
            Node* last = tail->prev;
            Node* temp = last->prev;
            temp->next = tail;
            tail->prev = temp;
            address.erase(last->key);
            delete(last);
            cap++;
        }

        cap--;
        Node* node = new Node(key, value);
        address[key] = node;
        addToHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */