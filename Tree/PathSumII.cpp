/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
 * equals the given sum.
 *
 * Note: A leaf is node with no children.
 *
 * Date: 06/24/2020
 * Author: Wei Du
 */
#include <vector>
#include <unordered_map>
using namespace std;

 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
	unordered_map<TreeNode*, int> state;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root) return {};
		vector<vector<int>> ret{};
		vector<TreeNode*> stk;
		vector<int> stkVal;
		int tmpSum{0};
		stk.push_back(root);
		stkVal.push_back(root->val);
		tmpSum += root->val;
		state[root] = 0;
		while (!stk.empty()) {
			TreeNode* tmp = stk.back();
			if (!tmp->left && !tmp->right) { // leaf
				if (tmpSum == sum)
					ret.push_back(stkVal);
				stk.pop_back();
				stkVal.pop_back();
				tmpSum-=tmp->val;
				continue;
			}
			switch (state[tmp]) {
				case 0:
					++state[tmp];
					if (tmp->left) {
						state[tmp->left] = 0;
						stk.push_back(tmp->left);
						stkVal.push_back(tmp->left->val);
						tmpSum += tmp->left->val;
					}
					break;
				case 1:
					++state[tmp];
					if (tmp->right) {
						state[tmp->right] = 0;
						stk.push_back(tmp->right);
						stkVal.push_back(tmp->right->val);
						tmpSum += tmp->right->val;
					}
					break;
				case 2:
					stk.pop_back();
					stkVal.pop_back();
					tmpSum-=tmp->val;
					break;
			}
		}
		return ret;
    }
};
