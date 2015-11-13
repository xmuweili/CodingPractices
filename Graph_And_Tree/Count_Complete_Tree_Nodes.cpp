/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Idea: By pass the computation of full tree. 
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode* left_leaf = root;
        TreeNode* right_leaf = root;
        int left_depth = 0;
        int right_depth = 0;

        while(left_leaf->left != NULL) {
        	left_leaf = left_leaf->left;
        	++left_depth;
        }

        while(right_leaf->right != NULL) {
        	right_leaf = right_leaf->right;
        	++right_depth;
        }
        if(left_depth == right_depth) return pow(2, right_depth + 1)-1;
        else return countNodes(root->left) + countNodes(root->right) + 1;
    }
};