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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 1;
        ListNode* n_plus_1 = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (i == n + 1 && n_plus_1 != nullptr) { n_plus_1 = n_plus_1->next; }
            else if (i == n + 1 && n_plus_1 == nullptr) { n_plus_1 = head; }
            else { ++i; }
            curr = curr->next;
        }   
        if (n_plus_1 == nullptr) {
           return head->next;
        } else if (n_plus_1->next != nullptr) {
            n_plus_1->next = n_plus_1->next->next;
        } else {
            n_plus_1->next = nullptr;
        }
        return head;
    }   
};
