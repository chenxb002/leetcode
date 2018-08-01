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
        dummy->next = NULL;
        ListNode *tail = dummy;
        ListNode *cur = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                int val = cur->val;
                while (cur && cur->val == val) { cur = cur->next; }
            } else {
                tail->next = cur;
                tail = tail->next;
                cur = cur->next;
            }
        }
        tail->next = NULL;
        return dummy->next;
    }
};


