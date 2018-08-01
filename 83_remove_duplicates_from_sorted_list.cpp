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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;
        ListNode *tail = cur;
        while (cur && cur->next) {
            while (cur->next && cur->next->val == cur->val) { cur = cur->next; }
            cur = cur->next;
            tail->next = cur;
            tail = tail->next;
        }
        if (tail) tail->next = NULL;
        return dummy->next;
    }
};


