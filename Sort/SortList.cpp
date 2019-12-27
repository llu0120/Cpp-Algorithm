/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        //Corner Case: 
        if (!head || !head->next) {
            return head;
        }
        //General Case: 
        ListNode* slow = head; 
        ListNode* fast = head; 
        ListNode* pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next; 
            fast = fast->next->next; 
        }
        //Need to make the mid pointer into NULL to seperate the linked list in to two parts 
        pre->next = NULL;
        return mergeList(sortList(head), sortList(slow));   
    }
    
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy; 
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1; 
                l1 = l1->next; 
            } else {
                current->next = l2; 
                l2 = l2->next; 
            }
            current = current->next; 
        }
        //If only left l1 
        if (l1) {
            current->next = l1;
        }
        //If only left l2
        if (l2) {
            current->next = l2;
        }
        
        return dummy->next; 
    }
};
