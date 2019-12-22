/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.

https://leetcode.com/problems/copy-list-with-random-pointer/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Corner Case: 
        if (head == NULL) {
            return nullptr;
        }
        
        //General Case 
        unordered_map<Node*, Node*> map;
        Node* result = new Node(head->val, nullptr, nullptr);
        Node* current = head->next; 
        Node* node = result; 
        map[head] = result;
        //Copy each node to the new node --> O(n)
        //Construct map for each old node and the new node --> search time O(1)
        while (current != NULL) {
            Node* tmp = new Node(current->val, nullptr, nullptr);
            node->next = tmp; 
            map[current] = tmp; 
            node = node->next;
            current = current->next;
        }
        
        node = result; 
        current = head; 
        //Search the map and Add random pointer to the new nodes 
        while (current != NULL) {
            node->random = map[current->random];
            node = node->next;
            current = current->next;
        }
        
        return result;
    }
};
