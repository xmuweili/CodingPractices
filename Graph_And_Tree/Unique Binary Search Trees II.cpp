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
	TreeNode* duplicate(TreeNode* root) {
		if(root == NULL) return NULL;
		TreeNode* d_root = new TreeNode(root->val);
		d_root->left = duplicate(root->left);
		d_root->right = duplicate(root->right);
		return root;
	}

	vector<TreeNode*> generateLeft(int start, int end, vector<TreeNode*> root) {
		if(start > end)
			return root;
		
	}


	vector<TreeNode*> generateLeft(int start, int end, vector<TreeNode*> root) {

	}

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) return res;

        if(n == 1) {
        	TreeNode* root = new TreeNode(n);
        	res.push_back(root);
        	return res;
        }

        for (int i = 1; i <= count; ++i)
        {
        	TreeNode* root = new TreeNode(n);
        	std::vector<TreeNode*> temp;
        	temp.push_back(root);
        	vector<TreeNode*> left_tree = generateLeft(1,i-1, temp);
        	vector<TreeNode*> full_tree = generateLeft(i+1,n, left_tree);
        	res.insert(res.begin(), full_tree.begin(), full_tree.end());
        }
        return res;
    }
};