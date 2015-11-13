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
    bool isAncestor(TreeNode* root, TreeNode* p) {
        if(root == NULL) return false;
        if(root == p) return true;
        if(root->left == p || root->left == p) return true;
        else return isAncestor(root->left, p) || isAncestor(root->right, p);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(p == root | q == root) return root;
        if(p == q) return q;
        TreeNode* ptr = root;
        while(1) {
            bool is_left_ancestor = isAncestor(ptr->left, p) && isAncestor(ptr->left, q);
            bool is_right_ancestor = isAncestor(ptr->right, p) && isAncestor(ptr->right, q);
            if(is_left_ancestor==false && is_right_ancestor ==false) break;
            else ptr = is_left_ancestor?ptr->left:ptr->right;
        }
        return ptr;
    }
};
