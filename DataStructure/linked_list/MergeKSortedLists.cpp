/* Divide and Conquer, Linked List
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size_lists = lists.size();
        //Corner Case: 
        if (size_lists == 0) {
            return NULL;
        }
        //General Case:
        while (size_lists > 1) {
            int mid = (size_lists + 1) / 2; //If size=5 --> mid=3, if size=4 --> mid=2
            //Divide and Conquer
            for (int i = 0; i < size_lists/2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i+mid]);//merge[0,3],[1,4],[2,5]
            }
            size_lists = mid; //The size will get smaller after the merge
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0); 
        ListNode* cur = result; 
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
        if (l1 != NULL) {
            cur->next = l1;
        } 
        if (l2 != NULL) {
            cur->next = l2; 
        } 
        return result->next;
    }
    
};
