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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int len = 0;
        ListNode *curr = head, *tail = NULL;
        while (curr != NULL) { len++; tail = curr; curr = curr->next; }
        k %= len;
        if (k == 0) { return head; }
        curr = head;
        for (int i = 1; i < len - k; ++i) { curr = curr->next; }
        tail->next = head;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};
