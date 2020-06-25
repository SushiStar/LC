/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// doing it iteratively
class Solution {
private:
    unordered_map<TreeNode *, int> state;

public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) return {};
        vector<int> ret;
        vector<TreeNode *> stk;
        stk.push_back(root);
        state[root] = 0;
        while (!stk.empty()) {
            TreeNode *tmp = stk.back();
            switch (state[tmp]) {
            case 0:
                ++state[tmp];
                if (tmp->left) {
                    state[tmp->left] = 0;
                    stk.push_back(tmp->left);
                }
                break;
            case 1:
                ++state[tmp];
                if (tmp->right) {
                    state[tmp->right] = 0;
                    stk.push_back(tmp->right);
                }
                break;
            case 2:
                ret.push_back(tmp->val);
                stk.pop_back();
                break;
            default:
                break;
            }
        }
        return ret;
    }
};
