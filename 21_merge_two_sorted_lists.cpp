/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL, *tail = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                if (res == NULL) { res = tail = l1; }
                else             { tail->next = l1; tail = tail->next;}
                l1 = l1->next;
            } else {
                if (res == NULL) { res = tail = l2; }
                else             { tail->next = l2; tail = tail->next;}
                l2 = l2->next;
            }
        }
        if (l1 != NULL) {
            if (res == NULL) { res = l1; }
            else             { tail->next = l1; }
        }
        if (l2 != NULL) {
            if (res == NULL) { res = l2; }
            else             { tail->next = l2; }
        }
        return res;
    }
};
