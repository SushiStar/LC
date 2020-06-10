/*
 * Find the sum of all left leaves in a given binary tree.
 *
 * Date: 06/08/2020
 * Author: Wei Du
 */

 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
		if (!root) return 0;
		// it's a leaf
		if (root->left && !root->left->left && !root->left->right)
			return root->left->val + sumOfLeftLeaves(root->right);
		return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};
