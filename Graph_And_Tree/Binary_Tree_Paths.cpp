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
    vector<string> binaryTreePaths(TreeNode* root) {
    	std::vector<string> res;

    	// Boundary conditions.
    	if(root == NULL)
    		return res;
        
        if(root->left == NULL && root->right == NULL)
    		res.push_back(std::to_string(root->val));
    	
    	// Recursive. 
    	if(root->left != NULL){
    		std::vector<string> left_s = binaryTreePaths(root->left);
    		for(std::vector<string>::iterator sit = left_s.begin();
    			sit != left_s.end(); ++sit) {

    			string s = std::to_string(root->val) + std::string("->") + *sit;
    			res.push_back(s);
    		}
    	}

		if(root->right != NULL){
    		std::vector<string> right_s = binaryTreePaths(root->right);
    		for(std::vector<string>::iterator sit = right_s.begin();
    			sit != right_s.end(); ++sit) {
    			string s = std::to_string(root->val) + "->" + *sit;
    			res.push_back(s);
    		}
    	}    	

    	return res;
    }
};