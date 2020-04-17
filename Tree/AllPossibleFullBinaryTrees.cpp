/*
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 * Return a list of all possible full binary trees with N nodes.
 * Each element of the answer is the root node of one possible tree.
 * Each node of each tree in the answer must have node.val = 0.
 * You may return the final list of trees in any order.
 *
 * Date: 04/16/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int N) {
        std::vector<std::vector<TreeNode *>> dp(N + 1,
                                                std::vector<TreeNode *>{});
        dp[1].push_back(new TreeNode(0));
        for (int i = 3; i <= N; i += 2) {
            for (int j = 1; j < i; j += 2) { // left j; right i-1-j
                for (auto l : dp[j]) {
                    for (auto r : dp[i - 1 - j]) {
                        TreeNode *root = new TreeNode(0);
                        root->left = copyTree(l);
                        root->right = copyTree(r);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[N];
    }

private:
    TreeNode *copyTree(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *cproot = new TreeNode(root->val);
        cproot->left = copyTree(root->left);
        cproot->right = copyTree(root->right);
        return cproot;
    }
};

class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int N) {
        std::vector<std::vector<TreeNode *>> dp(N / 2 + 2,
                                                std::vector<TreeNode *>{});
        dp[1].push_back(new TreeNode(0));
        for (int i = 3; i <= N; i += 2) {
            for (int j = 1; j < i; j += 2) { // left j; right i-1-j
                for (auto l : dp[j / 2 + 1]) {
                    for (auto r : dp[(i - 1 - j) / 2 + 1]) {
                        TreeNode *root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        dp[i / 2 + 1].push_back(root);
                    }
                }
            }
        }
        return dp[N / 2 + 1];
    }
};
