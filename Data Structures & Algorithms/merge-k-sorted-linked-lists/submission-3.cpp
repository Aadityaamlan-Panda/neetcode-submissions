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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if (!l1 & !l2) return nullptr;
        ListNode* head = new ListNode();
        ListNode* dummy = head;
        ListNode* prev = head;
        while(l1 && l2){
            if (l1->val<=l2->val){
                head->val = l1->val;
                l1 = l1->next;
            }
            else {
                head->val = l2->val;
                l2 = l2->next;
            }
            ListNode* tmp = new ListNode();
            head->next = tmp;
            prev = head;
            head = head->next;
        }
        while(l1){
            head->val = l1->val;
            l1 = l1->next;
            ListNode* tmp = new ListNode();
            head->next = tmp;
            prev = head;
            head = head->next;
        }
        while(l2){
            head->val = l2->val;
            l2 = l2->next;
            ListNode* tmp = new ListNode();
            head->next = tmp;
            prev = head;
            head = head->next;
        }
        prev->next = nullptr;
        delete head;
        return dummy;
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r){
        if (l > r) return nullptr;
        if (l == r) return lists[l];

        int mid = (l+r)/2;
        ListNode* left = mergeSort(lists,l,mid);
        ListNode* right = mergeSort(lists,mid+1,r);

        return mergeTwoLists(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = 0, r = lists.size()-1;
        return mergeSort(lists, l, r);
    }
};
