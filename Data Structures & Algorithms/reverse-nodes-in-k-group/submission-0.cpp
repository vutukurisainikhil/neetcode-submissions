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
        ListNode* curr = head;
        int count = 0;
        while(curr && count!=k){
            curr = curr->next;
            count++;
        }
        if(count != k){
            return head;
        }
        curr = head;
        ListNode* prev = NULL;
        ListNode* nexxt = NULL;
        while(curr && count){
            nexxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexxt;
            count--;
        }
        if(nexxt){
            head->next = reverseKGroup(nexxt, k);
        }
        return prev;
    }
};
