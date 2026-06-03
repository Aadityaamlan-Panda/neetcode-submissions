class Node{
public:
    int ky;
    int val;

    Node* next;
    Node* prev;
};

class LRUCache {
public:
    unordered_map<int,Node*>mp;

    int cap, len = 0;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key)==mp.end()) return -1;
        Node* curr = mp[key];
        erase(curr);
        insertMRU(curr);
        return curr->val;
    }

    void eraseLRU(){
        Node* curr = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        mp.erase(curr->ky);
        delete curr;
        len--;
    }

    void erase(Node* curr){
        Node* last = curr->prev;
        Node* flw = curr->next;
        last->next = flw;
        flw->prev = last;
    }

    void insertMRU(Node* curr){
        Node* end = tail->prev;
        curr->next = tail;
        curr->prev = end;
        end->next = curr;
        tail->prev = curr;
    }

    void insert(int key, int value){
        if (len==cap) eraseLRU();
        Node* curr = new Node();
        curr->ky = key;
        curr->val = value;
        insertMRU(curr);
        len++;
        mp[key] = curr;
    }

    void modify(int key, int value){
        Node* curr = mp[key];
        curr->val = value;
        erase(curr);
        insertMRU(curr);
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()) modify(key,value);
        else insert(key,value);
    }
};
