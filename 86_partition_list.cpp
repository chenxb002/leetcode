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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = dummy;
        while (cur->next && cur->next->val < x) {
            cur = cur->next;
            pre = pre->next;
        }
        while (cur && cur->next) {
            if (cur->next->val < x) {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                temp->next = pre->next;
                pre->next = temp;
                pre = pre->next;
            } else {
                cur = cur->next;
                if (pre->next && pre->next->val < x) {
                    pre = pre->next;
                }
            }
        }
        return dummy->next;
    }
};


