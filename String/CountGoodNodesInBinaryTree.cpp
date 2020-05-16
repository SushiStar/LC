/*
 * Given a binary tree root, a node X in the tree is named good if 
 * in the path from root to X there are no nodes with a value greater
 * than X.
 * Return the number of good nodes in the binary tree.
 * The number of nodes in the binary tree is the range [1, 10^5].
 * Each node's valude is between [-10^4, 10^4].
 *
 * Date: 05/16/2020
 * Author: Wei Du
 */
#include <vector>
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
public:
    int goodNodes(TreeNode* root) {
        int ret{0};
        if (!root) return ret;
        ++ret;
        goodNodes(root->left, ret, root->val);
        goodNodes(root->right, ret, root->val);
        return ret;
    }
private:
    void goodNodes(TreeNode* root, int &ret, int currMax) {
        if (!root) return;
        if (root->val >= currMax) {
            ++ret;
            currMax = root->val;
        }
        goodNodes(root->left, ret, currMax);
        goodNodes(root->right, ret, currMax);
    }
};
