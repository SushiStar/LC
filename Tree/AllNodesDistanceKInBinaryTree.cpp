/*
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K. Return a list of the values of all nodes  that have a
 * distance K from the target node. The answer can be returned in any order.
 *
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500;
 * The target node is a node in the tree.
 * 0 <= K <= 1000
 *
 * Date: 06/08/2020
 * Author: Wei Du
 */

#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        if (!root || !target) return {};
        if (K == 0) return {target->val};
        constructGraph(root);
        std::deque<int> bfsList;
        bfsList.push_back(target->val);
        int levelSize(1);
        int pathLength(0);
        while (!bfsList.empty() && pathLength < K) {
            while (levelSize > 0) {
                --levelSize;
                int curr = bfsList.front();
				visited[curr] = true;
                bfsList.pop_front();
                for (int neighb : neighbors[curr]) {
                    if (visited[neighb]) continue;
                    visited[neighb] = true;
                    bfsList.push_back(neighb);
                }
            }
            levelSize = (int)bfsList.size();
            ++pathLength;
        }
        return std::vector<int>(bfsList.begin(), bfsList.end());
    }

private:
    bool visited[501] = {false};
    vector<int> neighbors[501] = {};
    void constructGraph(TreeNode *root) {
        if (!root) return;
        if (root->left) {
            neighbors[root->val].push_back(root->left->val);
            neighbors[root->left->val].push_back(root->val);
            constructGraph(root->left);
        }
        if (root->right) {
            neighbors[root->val].push_back(root->right->val);
            neighbors[root->right->val].push_back(root->val);
            constructGraph(root->right);
        }
    }
};
