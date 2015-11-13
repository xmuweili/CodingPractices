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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);

        int mid_point = nums.size()/2;
        std::vector<int> left_num(nums.begin(), nums.begin()+mid_point);
        std::vector<int> right_num(nums.begin()+mid_point+1, nums.end());
        int mid_point_val = *(nums.begin()+mid_point);
        TreeNode* root = new TreeNode(mid_point_val);
        root->left = sortedArrayToBST(left_num);
        root->right = sortedArrayToBST(right_num);
        return root;
    }
};