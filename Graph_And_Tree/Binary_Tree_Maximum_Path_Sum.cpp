/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Init thoughts: 
// 1. Solve the problem: max sum when pass through the given node
 // 1.1 There are two situations can happen: (a) the path is from root->child (2) the path is child ->root->child.
// 2. Compute step 1 for all the tree nodes to got final answer. 
typedef std::vector<int> Path;
class Solution {
public:
	// This function returns the max child->root rum, store the max in res.
	int helper(TreeNode* root, int* res) {
		if(root == NULL) return 0;

		int cr_left = helper(root->left, res);
		int cr_right = helper(root->right, res);

		// Check child->root case.
		int cr_left_sum = cr_left + root->val;
		int cr_rihgt_sum = cr_right + root->val;
		int crc_sum = root->val + cr_right + cr_left;

		int max = std::max(std::max(crc_sum, root->val), std::max(cr_left_sum, cr_rihgt_sum));
		if (*res < max) *res = max;
		return std::max(root->val, std::max(cr_left_sum, cr_rihgt_sum));
	}

    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int max = -10000;
        helper(root, &max);
        return max;
    }
};