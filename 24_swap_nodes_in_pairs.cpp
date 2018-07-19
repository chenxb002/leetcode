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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next_node;
        while (curr != NULL && curr->next != NULL) {
            if (prev != NULL) { prev->next = curr->next; }
            next_node = curr->next->next;
            curr->next->next = curr;
            prev = curr->next;
            curr->next = next_node;
            curr = next_node;
        }
        return head;
    }
};
