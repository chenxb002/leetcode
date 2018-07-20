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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) { return head; }
        ListNode *helper = new ListNode(-1);
        helper->next = head;
        ListNode *pre = helper, *curr = head;
        int i = 0;
        while (curr) {
          ++i;
          if (i % k == 0) {
              pre = reverseGroup(pre, curr->next);
              curr = pre->next;
          } else {
             curr = curr->next;
          }
        }
        return helper->next;
    }

    ListNode* reverseGroup(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *curr = last->next;
        while (curr != next) {
            last->next = curr->next;
            curr->next = pre->next;
            pre->next  = curr;
            curr       = last->next;
        }
        return last;
    }
};
