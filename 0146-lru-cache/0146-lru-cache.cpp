struct Node {
    int key, val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int cap = 0;
    unordered_map<int, Node*> map;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void putInFront(Node* node){
        Node* temp = head->next;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if(map.count(key)){
            Node* node = map[key];
            deleteNode(node);
            putInFront(node);
            return node->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            Node* node = map[key];
            node->val = value;

            deleteNode(node);
            putInFront(node);
            return;
        }

        Node* node = new Node(key, value);

        if(cap == 0){
            Node* penNode = tail->prev;
            Node* newPen = penNode->prev;

            newPen->next = tail;
            tail->prev = newPen;

            map.erase(penNode->key);
            delete(penNode);
            cap++;
        }
            
        putInFront(node);
        map[key] = node;
        cap--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */