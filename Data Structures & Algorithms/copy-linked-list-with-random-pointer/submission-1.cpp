/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* dummy = new Node(head->val);
        unordered_map<Node*,Node*>paired;
        Node* tail = dummy;
        Node* curr = head;
        paired[curr] = dummy;
        while(curr->next){
            curr = curr->next;
            Node* tmp = new Node(curr->val);
            tail->next = tmp;
            tail = tmp;
            paired[curr] = tail;
        }
        Node* start = dummy;
        while(start){
            start->random = paired[head->random];
            head= head->next;
            start = start->next;
        }
        return dummy;
    }
};
