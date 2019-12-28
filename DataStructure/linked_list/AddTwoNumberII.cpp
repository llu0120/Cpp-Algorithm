/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
        stack<int> s1; 
        stack<int> s2; 
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next; 
        } 
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next; 
        }
        
        int sum = 0; 
        vector<int> resultNum; 
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            int digit = sum % 10;
            sum /= 10; //carry 
            resultNum.push_back(digit);
        }
        
        //If sum still have value != 0 --> there is a carry which needs to add to the resultNum vector
        if (sum != 0) {
            resultNum.push_back(sum);
        }
        
        //Put numbers into linked list
        vector<int> revNum(resultNum.rbegin(), resultNum.rend());
        ListNode* result = new ListNode(0);
        ListNode* current = result;
        for (int i = 0; i < revNum.size(); i++) {
            current->next = new ListNode(revNum[i]);        
            current = current->next;
        }
        return result->next;
    }
};
