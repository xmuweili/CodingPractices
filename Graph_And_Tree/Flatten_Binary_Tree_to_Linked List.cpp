/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Init thought: a recursive problem. 
// root -> {[left tree] to list} -> {[right tree] to list}
class Solution {
public:
	// Get the end node a list
	TreeNode* rightend(TreeNode* root) {
		if(root == NULL) 
			return root;
		TreeNode* pt = root;
		while(pt->right != NULL) {
			pt = pt->right;
		}
		return pt;
	}

  void flatten(TreeNode* root) {
  	if(root == NULL)
  		return;

  	TreeNode* right_child  = root->right;
  	TreeNode* left_child = root->left;

  	if(right_child == NULL && left_child == NULL)
  		return;
  	
  	// Flat the left childs.
  	if(left_child != NULL)
  	{
  		root->right = left_child;
  		root->left = NULL;
  		flatten(left_child);
  	}
  	TreeNode* tail = left_child == NULL?root:rightend(left_child);

  	// Flat the right childs.
  	if(right_child != NULL)
  	{
  		tail->right = right_child;
  		tail->left = NULL;
  		flatten(right_child);
  	}
  }
};