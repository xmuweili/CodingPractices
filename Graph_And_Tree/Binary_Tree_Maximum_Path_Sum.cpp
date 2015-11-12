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
// 2. Compute step 1 for all the tree nodes to got final answer. 
typedef std::vector<int> Path;
class Solution {
public:
	int pathSum(Path p) {
		int sum = 0;
		for (int i = 0; i < p.size(); ++i)
		{
			sum += p[i];
		}
		return sum;
	}
	int maxSum(std::vector<Path> pathes) {
		if(pathes.size() == 0) return 0;
		int max = pathSum(pathes[0]);
		for (int i = 1; i < pathes.size(); ++i)
		{
			int p_sum = pathSum(pathes[i]);
			if(max < p_sum)
				max = p_sum;
		}
		return max;
	}

	std::vector<Path> getPathes(TreeNode* root) {
		std::vector<Path> pathes;
		if(root == NULL)
			return pathes;

		if(root->right == NULL && root->left == NULL)
		{   
		    Path p;
			p.push_back(root->val);
			pathes.push_back(p);
			return pathes;
		}

		if(root->left != NULL) {
			std::vector<Path> left_pathes = getPathes(root->left);
			// Insert the root-value to the beginning of path.
			for (int i = 0; i < left_pathes.size(); ++i)
			{
				Path p = left_pathes[i];
				p.insert(p.begin(), root->val);
				left_pathes[i] = p;
			}
			pathes.insert(pathes.begin(), 
				left_pathes.begin(), left_pathes.end());
		}

		if(root->right != NULL) {
			std::vector<Path> right_pathes = getPathes(root->right);
			for (int i = 0; i < right_pathes.size(); ++i)
			{
				Path p = right_pathes[i];
				p.insert(p.begin(), root->val);
				right_pathes[i] = p;
			}
			pathes.insert(pathes.begin(), 
				right_pathes.begin(), right_pathes.end());
		}
		return pathes;
	}

	int maxPathSumThroughRoot(TreeNode* root) {
		if(root == NULL)
			return 0;
		if(root->left == NULL && root->right == NULL)
			return root->val;
			
        int pathsum = 0;
		if(root->left != NULL) {
			std::vector<Path> pathes = getPathes(root->left);
			pathsum += maxSum(pathes);
		}
		if(root->right != NULL) {
			std::vector<Path> pathes = getPathes(root->right);
			pathsum += maxSum(pathes);
		}
		return pathsum + root->val;
	}

    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int max_sum = maxPathSumThroughRoot(root);
        int left_sum = maxPathSumThroughRoot(root->left);
        if(max_sum < left_sum) max_sum = left_sum;
        int right_sum = maxPathSumThroughRoot(root->right);
        if(max_sum < right_sum) max_sum = right_sum;
        return max_sum;
    }
};