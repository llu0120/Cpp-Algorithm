/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
**/
//Iteratively method
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //corner case: if the node is null or there is only one node 
        if (head == NULL || head->next == NULL){
            return head;
        }
        //general case
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr->next;
        while(curr != NULL){
            //make curr->next point to prev(reverse)
            curr->next = prev;
            //Update prev, curr and next
            prev = curr;
            curr = next;
            if (curr != NULL){
                next = curr->next;
            }
        }
        return prev;
    }
};

//Recursizely method https://www.youtube.com/watch?time_continue=233&v=MRe3UsRadKw
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        (head->next)->next = head;
        head->next = NULL;
        return newHead;
    }
};
