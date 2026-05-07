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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // firstly need to create dummy 0, to pass some edge cases as returning.
        ListNode* temp = new ListNode(0);
        ListNode* res = temp;
        while( l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
                //cout<<" L1:"<<temp->val<<endl;
            }
            else if(l1->val > l2->val){
                //cout<<" L2:"<<l2->val<<endl;
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        // when any one of the list is empty, need to append another list to result
        while(l1!=NULL){
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2!=NULL){
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        //some cases, returning NULL throws error.
        return res->next;
    }
};
