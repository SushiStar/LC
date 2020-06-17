/*
 * Given a non-empty binary tree, find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes form some
 * starting node to any node in the tree along the parent-child connections. The
 * path must contain at least one node and does not need to go through the root.
 *
 * Date: 06/16/2020
 * Author: Wei Du
 */
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxPathSum(TreeNode *root) {
		if (!root) return 0;
		ret = root->val;
        maxSum(root);
        return ret;
    }

private:
    int ret{0};
	int maxSum(TreeNode *root) {
		if (!root) return 0;
		int leftSum{maxSum(root->left)};
		int rightSum{maxSum(root->right)};
		int currSum{root->val};
		currSum += leftSum > 0 ? leftSum : 0;
		currSum += rightSum > 0 ? rightSum : 0;
		ret = ret > currSum ? ret : currSum;
		return std::max(std::max(leftSum, rightSum), 0) + root->val;
	}
};
