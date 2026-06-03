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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1; ListNode* p2 = l2;
        while(p1 && p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2) return addTwoNumbers(l2, l1);

        ListNode* dummy = l1;
        ListNode* tail = l1;
        while(tail->next) tail = tail->next;

        int carry = 0;
        while(l2){
            int sum = l1->val + l2->val + carry;
            l1->val = sum%10;
            carry = sum/10;
            l1 = l1->next; l2 = l2->next;
        }
        while(carry && l1){
            int sum = l1->val + carry;
            l1->val = sum%10;
            carry = sum/10;
            l1 = l1->next;
        }
        if (carry){
            ListNode* tmp = new ListNode(carry);
            tail->next = tmp;
        }
        return dummy;
    }
};
