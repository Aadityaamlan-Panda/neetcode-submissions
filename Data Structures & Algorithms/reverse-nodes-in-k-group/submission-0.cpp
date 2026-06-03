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
private:
    ListNode* reverse(ListNode* prev, ListNode* end){
        ListNode* curr = prev->next;
        ListNode* head = curr;
        ListNode* headprev = prev;
        ListNode* endnext = end->next;
        while(curr!=endnext){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        headprev->next = prev;
        head->next = endnext;
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p1 = &dummy;
        ListNode* p2 = head;
        while(p2){
            int i;
            ListNode* prev = p2;
            for (i = 0; i < k && p2; i++){
                prev = p2;
                p2 = p2->next;
            }
            if(i>=k) {
                p1 = reverse(p1, prev);
            }
        }
        return dummy.next;
    }
};
