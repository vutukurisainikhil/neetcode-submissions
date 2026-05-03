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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
                // creating 
        ListNode* dummy  = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i=0;i<n;i++){
            first = first->next;
        }
        while(first->next!=NULL){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        // passing dummy->next, to pass edge cases when nodes are empty 
        // (retuning NULL throws an error)
        return dummy->next;
    }
};
