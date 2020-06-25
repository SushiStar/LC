/*
 * Given a binary tree, return all duplicate binary trees. For each  kind of
 * duplicate subtrees, you only need to return  the root node of any one of
 * them.
 * Two trees are duplicate if they have the same structure with same node
 * values.
 *
 * Date: 06/24/2020
 * Author: Wei Du
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        if (!root) return ret;
        encodeTree(root);
        return ret;
    }

private:
    unordered_map<string, int> exist;
    vector<TreeNode *> ret{};
    string encodeTree(TreeNode *root) {
        if (!root) return "null";
        string leftEncode = encodeTree(root->left);
        string rightEncode = encodeTree(root->right);
        string currEncode{leftEncode + ',' + rightEncode + ',' + to_string(root->val) };
		if (exist[currEncode]++ == 1)
			ret.push_back(root);
		return currEncode;
    }
};
