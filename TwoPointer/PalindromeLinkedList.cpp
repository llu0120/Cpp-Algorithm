/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        vector<int> arrayInt; 
        ListNode* current = head; 
        while (current != nullptr) {
            arrayInt.push_back(current->val);
            current = current->next;
        }
        
        
        int length = arrayInt.size();
        int left = 0;
        int right = length - 1;
        //Even Case 
        if (length % 2 == 0) {
            while (left < right) {
                if (arrayInt[left] == arrayInt[right]) {
                    left++; 
                    right--; 
                } else {
                    return false; 
                }
            }
        } else { //Odd Case  
            int mid = (left + right) / 2; 
            left = mid - 1;
            right = mid + 1; 
            while (left >= 0 && right <length) {
                if (arrayInt[left] == arrayInt[right]) {
                    left--;
                    right++; 
                } else {
                    return false; 
                }
            }
        }
        return true; 
    }
};
