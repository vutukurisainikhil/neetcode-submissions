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
    // Time Complexity: 0(nlogk)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*t = NULL;
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(auto c:lists){
            t=c;
            while(t){
                minHeap.push(t->val);
                t=t->next;
            }
        }
        // creating linkedlist from back to head;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(!minHeap.empty()){
            cur->next = new ListNode(minHeap.top());;
            cur = cur->next;
            minHeap.pop();
        }
        return res->next;
    }
};
