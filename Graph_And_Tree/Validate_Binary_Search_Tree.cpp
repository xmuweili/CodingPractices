/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool largerThan(TreeNode* root, int val) {
		if(root->val <= val) return false;
		if(root->left != NULL) {
			if(!largerThan(root->left, val))
				return false;
		}
		if(root->right != NULL) {
			if(!largerThan(root->right, val))
				return false;
		}
		return true;
	}

	bool lessThan(TreeNode* root, int val) {
		if(root->val >= val) return false;
		if(root->left != NULL) {
			if(!lessThan(root->left, val))
				return false;
		}
		if(root->right != NULL) {
			if(!lessThan(root->right, val))
				return false;
		}
		return true;
	}


    bool isValidBST(TreeNode* root) {
    	if(root == NULL) return true;
    	if(root->left == NULL && root->right == NULL) return true;

    	if(root->left != NULL) {
    		if(!lessThan(root->left, root->val))
    		{
    			return false;
    		}
    		if(!isValidBST(root->left)){
    			return false;
    		}
    	}
		
		if(root->right != NULL) {
    		if(!largerThan(root->right, root->val)){
    			return false;
    		}
    		if(!isValidBST(root->right)){
    			return false;
    		}
    	}

    	return true;
    }
};