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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len =0; 
        ListNode* ctr = head;
        while(ctr){
            len++;
            ctr = ctr->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;

        if (len - n ==0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int i=0;
        while(curr){
            if (i==len-n){
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        return head;
    }
};
