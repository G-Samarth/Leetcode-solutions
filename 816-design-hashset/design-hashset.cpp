class MyHashSet {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int key): val(key), next(NULL) {}
    };

    vector<ListNode*> set;

    int hash(int key){
        return key % set.size();
    }
public:
    MyHashSet() {
        set.resize(10000);
        for(auto& s:set)
            s = new ListNode(-1);
    }
    
    void add(int key) {
        int h = hash(key);

        ListNode* head = set[h];
        while(head->next){
            if(head->next->val == key)
                return;
            head = head->next;
        }
        
        head->next = new ListNode(key);
    }
    
    void remove(int key) {
        int h = hash(key);

        ListNode* head = set[h];
        while(head->next){
            if(head->next->val == key){
                ListNode* temp = head->next;
                head->next = temp->next;
                delete temp;
                return;
            }
            head = head->next;
        }
    }
    
    bool contains(int key) {
        int h = hash(key);

        ListNode* head = set[h];
        while(head->next){
            if(head->next->val == key)
                return true;
            head = head->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */