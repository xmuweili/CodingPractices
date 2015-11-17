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

	vector<TreeNode*> generate(int start, int end) {
		vector<TreeNode*> res;	
		if(start > end) res.push_back(NULL);
		if(start == end) res.push_back(new TreeNode(start));
		if(start < end){
			for (int i = start; i <= end; ++i)
			{
				vector<TreeNode*> left_trees = generate(start, i-1);
				vector<TreeNode*> right_trees = generate(i+1, end);
				for(int j=0; j<left_trees.size(); ++j)
					for(int k=0; k<right_trees.size(); ++k) {
						TreeNode* root = new TreeNode(i);
						root->left = left_trees[j];
						root->right = right_trees[k];
						res.push_back(root);
					}
			}
		}
		return res;
	}

    vector<TreeNode*> generateTrees(int n) {
    	return generate(1,n);
    }
};