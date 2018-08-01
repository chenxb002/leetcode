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
        ListNode *tail = dummy;
        ListNode *cur = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
               int val = cur->val;
               while (cur && cur->val == val) { cur = cur->next; }
            } else {
               tail->next = cur;
               tail = tail->next;
            }
        }
        return dummy->next;
    }
};
