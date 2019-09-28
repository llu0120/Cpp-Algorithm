/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0); //Build a result ListNode
        ListNode* cur = result; //Build a moving pointer
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        //If l1 already finish adding, then directly add all of the rest l2 into the result ListNode  
        //If l2 already finish adding, then directly add all of the rest l1 into the result ListNode  
        if (l1 != NULL) {
            cur->next = l1;
        } else {
            cur->next = l2;
        }
        return result->next;
    }
   
};
