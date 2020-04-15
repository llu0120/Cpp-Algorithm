/*

	   1
      / \
     2   3 
    / \  
   4   5
The sum of the leaves will be 4 + 5 + 3 = 12, so return 12. 

*/ 
struct TreeNode {
	int val; 
	TreeNode* left; 
	TreeNode* right; 
	TreeNode(int n) : val(n), left(NULL), right(NULL) {} 
}; 

int sumofLeaves(TreeNode* root) {
	if (!root) {
		return 0; 
	}
	if (root->left || root->right) {
		return sumofLeaves(left) + sumofLeaves(right); 
	}
	//if !root->left && !root->right
	return root->val; 
}
