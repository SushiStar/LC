/*
 * Two elements of a binary search tree are swapped by mistake.
 * Recover the tree without changing the structure.
 *
 * Date: 03/14/2020
 * Author: Wei Du
 */
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        std::vector<TreeNode *> inorder;
        std::stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                inorder.push_back(root);
                root = root->right;
            }
        }
        TreeNode *mark1{nullptr}, *mark2{nullptr};
        for (int i = 1; i < inorder.size(); ++i) {
            if (inorder[i]->val <= inorder[i - 1]->val) {
                if (!mark1) {
                    mark1 = inorder[i - 1];
                    mark2 = inorder[i];
                    continue;
                } else {
                    mark2 = inorder[i];
                    break;
                }
            }
        }
        std::swap(mark1->val, mark2->val);
    }
};

class Solution0 {
public:
    void recoverTree(TreeNode *root) {
        checkSubTree(root);
        std::swap(mark1->val, mark2->val);
    }

private:
    TreeNode *prevNode{nullptr}, *mark1{nullptr}, *mark2{nullptr};
    void checkSubTree(TreeNode *root) {
        if (!root) return;
        checkSubTree(root->left);
        if (prevNode && prevNode->val >= root->val) {
            if (!mark1) {
                mark1 = prevNode;
            }
            mark2 = root;
        }
        prevNode = root;
        checkSubTree(root->right);
    }
};
