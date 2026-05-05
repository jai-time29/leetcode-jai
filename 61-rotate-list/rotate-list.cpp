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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        ListNode* temp = head;
        int n = 1;
        while (temp->next) {
            temp = temp->next;
            n++;
        }

        // Step 2: Reduce k
        k = k % n;
        if (k == 0) return head;

        // Step 3: Make circular
        temp->next = head;

        // Step 4: Find new tail (n-k-1 steps)
        ListNode* curr = head;
        for (int i = 0; i < n - k - 1; i++) {
            curr = curr->next;
        }

        // Step 5: Break and return
        ListNode* newHead = curr->next;
        curr->next = NULL;

        return newHead;
    }
};