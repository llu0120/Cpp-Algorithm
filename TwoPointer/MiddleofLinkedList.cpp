//Two Pointer
/**Find the middle node of a linked list.
* Example
* Example 1:
* Input:  1->2->3
* Output: 2	
* Explanation: return the value of the middle node.

* Example 2:
* Input:  1->2
* Output: 1	
* Explanation: If the length of list is  even return the value of center left one.
*/
 
/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        // write your code here
        if (head == nullptr){
            return head;
        }
        ListNode *fast = head->next;   // fast points to 2 (If the length of list is  even return the value of center left one.)
        ListNode *slow = head;  //slow points to 1 
        while (fast != nullptr && fast -> next != nullptr){  //For the case 1->2->null, if we didn't have the condition: fast -> next != nullptr, pointer fast will move to fast->next->next. Then it will occur core dump error.
            slow = slow -> next;
            fast = fast -> next -> next; //fast 
        }
        return slow;
    }
};
