/**
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head; 
        ListNode *slow = head; 
        //Use fast and slow pointer to detect if there is a cycle 
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; 
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        //This means the linked list doesn't have a cycle
        if (fast == NULL || fast->next == NULL) {
            return NULL;    
        }
        //This means the linked list has a cycle. 
        //Make the slow pointer start from head, the fast pointer will go two times faster than the slow pointer. So the next time the fast and slow pointer meets, this means the node is where the cycle begins.
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
