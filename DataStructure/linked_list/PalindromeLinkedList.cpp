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
    //This is a method to find the middle of the index and reverse the second half of the linked-list 
    bool isPalindrome(ListNode* head) {
        //Corner Case: 
        if (head == nullptr || head->next == nullptr) {
            return true; 
        }
        //General Case:
        ListNode* slow = head; 
        ListNode* fast = head; 
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next; 
            fast = fast->next->next; 
        }
        
        ListNode* startRev = slow->next; //The index ListNode that start the reverse 
        ListNode* start = head;
        
        //Reverse the second half of the linked-list 
        slow->next = reverseList(startRev);
        
        //Compare the first half and the second half to determine it is a palindrome or not
        while (slow->next != nullptr) {
            slow = slow->next; 
            if (start->val != slow->val) {
                return false;
            }
            start = start->next; 
        }
        return true; 
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head; 
        }
        ListNode* newHead = reverseList(head->next);
        (head->next)->next = head;
        head->next = nullptr;
        return newHead; 
    }
};
