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
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto c:lists){
            t=c;
            while(t){
                pq.push(t->val);
                t=t->next;
            }
        }
        // creating linkedlist from back to head;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while(!pq.empty()){
            cur->next = new ListNode(pq.top());;
            cur = cur->next;
            pq.pop();
        }
        return res->next;
    }
};
