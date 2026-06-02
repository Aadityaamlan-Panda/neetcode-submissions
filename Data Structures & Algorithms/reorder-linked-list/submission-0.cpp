/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
       if (!head || !head->next) return;
       int len = 0;
       ListNode* tail = head;

       while(tail){
        len++; tail = tail->next;
       }

       int rev_pos = len/2;
       
       ListNode* lwr_prev = head;
       for(int i=0; i<rev_pos;i++) lwr_prev = lwr_prev->next;

       ListNode* curr = lwr_prev->next;
       lwr_prev->next = nullptr;
       
       ListNode* prev = nullptr;

       while(curr){
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
       }

       ListNode* start = head;
       int i = 0;
       while (start && prev){
        ListNode* tmp = start->next;
        start->next = prev;
        start = tmp;
        tmp = prev->next;
        prev->next = start;
        prev = tmp;
        i+=2;
       }       
    }
};

