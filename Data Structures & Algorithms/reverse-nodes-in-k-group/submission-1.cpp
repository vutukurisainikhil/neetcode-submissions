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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // Check if there are K nodes in the list
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }

        ListNode* curr = head;
        ListNode* nexxt = NULL;
        ListNode* prev = NULL;

        int count = 0;

        while (curr != NULL && count < k) {
            nexxt = curr->next;
            curr->next = prev; // rotating
            prev = curr;
            curr = nexxt;
            count++;
        }

        if (nexxt) {
            head->next = reverseKGroup(nexxt, k);
        }
        return prev;
    }
};