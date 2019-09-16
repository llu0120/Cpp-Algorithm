/**
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/24md.html
 */

//Iteration Method
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
	//Corner case
        if (head == NULL || head->next == NULL) {
            return head;
        }
        //General case
        ListNode *FirstNode = new ListNode(0);
        FirstNode->next = head;
        ListNode *prev = FirstNode;
        ListNode *cur = head;
        ListNode *nextPair;
        while (cur != NULL && cur->next != NULL) {
            //Assume dealing with the case 1->2->3->4
            nextPair = cur->next->next; //Stoe the next pair (3->4) 
            (cur->next)->next = cur; //Link 2 to 1 
            prev->next = cur->next; //Link FirstNode to 2 
            cur->next = nextPair; //Link 1 to NextPair
            
            //Move on to next pair
            prev = cur; 
            cur = cur->next; 
        }
        return FirstNode->next; 
    }
};

//Recursion Method
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //Corner case
        if (head == NULL || head->next == NULL) {
            return head;
        }
        //General case
        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        
        return newHead;
    }
};
