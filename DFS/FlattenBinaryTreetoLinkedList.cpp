/**
* Flatten a binary tree to a fake "linked list" in pre-order traversal.
* Here we use the right pointer in TreeNode as the next pointer in ListNode.
* Example
* Example 1:
* Input:
* {1,2,5,3,4,#,6}
*     1
*    / \
*   2   5
*  / \   \
* 3   4   6
* Output:
* {1,#,2,#,3,#,4,#,5,#,6}
* 1
*  \
*   2
*    \
*     3
*      \
*       4
*        \
*         5
*          \
*           6
* Example 2:
* Input:
* {1}
* 1
* Output:
* {1}
* 1
* Challenge
* Do it in-place without any extra memory.
* Notice
* Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
//DFS Recursive
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return ; 
        }
        if (root->left != NULL) {
            flatten(root->left);        
        }
        if (root->right != NULL) {
            flatten(root->right);        
        }
        if (root->left == NULL) { //This means all the node are on the right now --> finished flatten
            return; 
        } 
        //for example set root = 2 
        TreeNode* tmp = root->left; //Stored the left node as tmp --> store 3
        while (tmp->right != NULL) { //If the tmp still have right node, keep traverse to the rightest node --> 3 is has no right node 
            tmp = tmp->right; 
        }
        tmp->right = root->right; //When arrived the rightest node, bridge the original right node to the tmp->right --> brige 4 on to 3
        root->right = root->left; //Then bridge the left node on to the root --> bridge 3 on to 2
        root->left = NULL; //Set the root->left to null
        
    }
};
 
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        if (root == nullptr) return ;
        if (root -> left != nullptr) flatten(root -> left); // recursive to the left
        if (root -> right != nullptr) flatten(root -> right); // recursive to the right
        
        TreeNode* temp = root -> right; //store the right node in temp
        root -> right = root -> left; // Cut off the right node, then bridge the left node in the right node. 
        root -> left = nullptr; // Set the left into nullptr.
        while (root -> right != nullptr) root = root -> right; //Trasversal to the most right node that root -> right == NULL, then we append the temp node to its right. 
        root -> right = temp; // put the right node back to the tree. 
    }
};

//Non-Recursive
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        TreeNode* current = root; 
        while (current != nullptr){ 
            if (current -> left != nullptr){   //if current node has left child
                TreeNode* p = current -> left; // set pointer p as the left child
                while (p -> right != nullptr) p = p -> right; // move p to the right most node of the left child
                p -> right = current -> right;  //make the right child of the current node bridge into node p's right child
                current -> right = current -> left; //make the left child of the current node into the right child
                current -> left = nullptr; // set the left child of the current node into nullptr
            }
            current = current -> right; // move the current to the right until current == nullptr
        }
    }
};
