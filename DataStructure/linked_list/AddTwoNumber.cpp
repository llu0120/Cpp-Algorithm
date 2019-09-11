/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0); // a node with 0 value
        ListNode *list1 = l1, *list2 = l2, *result = l3;
        int carry = 0;
        int sum = 0; 
        int last_digit; 
        
        //If both lis1 and list2 have values
        while (list1 != NULL && list2 != NULL) {
            sum = list1->val + list2->val + carry;
            carry = sum/10; //To determine whether there is a carry number 
            last_digit = sum%10; //To determine the digit that should be in this add
            result->next = new ListNode(last_digit);
            
            list1 = list1->next;
            list2 = list2->next;
            result = result->next;
        }
        
        //If there is value in list1 or list2 or there is a carry
        while (list1 != NULL || list2 != NULL || carry != 0) {
            sum = carry; 
            if (list1 != NULL) {
                sum += list1->val;
                list1 = list1->next;
            }
            if (list2 != NULL) {
                sum += list2->val;
                list2 = list2->next;
            }
            carry = sum/10; 
            last_digit = sum%10;
            result->next = new ListNode(last_digit);
            result = result->next;
        } 
        return l3->next; 
    }
};
