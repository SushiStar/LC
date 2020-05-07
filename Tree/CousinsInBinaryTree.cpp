/*
 * In a binary tree, the root node is at depth 0, and children of each depth
 * k node are at depth k+1. Two nodes of a binary tree are cousins if they have
 * the same depth, but have different parents.
 * We are given the root of a binary tree with unique values, and the values
 * x and y of two different nodes in the tree. Return true if and only if
 * the nodes corresponding to the values x and y are cousins.
 *
 * Date: 05/07/2020
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root || x == root->val || y == root->val || x == y)
            return false;
        bool xfound{false}, yfound{false};
        TreeNode* xparent = nullptr;
        TreeNode* yparent = nullptr;
        std::vector<TreeNode*> bfs[2];
        bfs[0].push_back(root);
        while (!bfs[0].empty()) {
            for (auto p : bfs[0]) {
                if (p->left) {
                    bfs[1].push_back(p->left);
                    if (p->left->val == x){
                        xparent = p;
                        xfound = true;
                    } 
                    if (p->left->val == y) {
                        yparent = p;
                        yfound = true;
                    }
                }
                if (p->right) {
                    bfs[1].push_back(p->right);
                    if (p->right->val == x){
                        xparent = p;
                        xfound = true;
                    } 
                    if (p->right->val == y) {
                        yparent = p;
                        yfound = true;
                    }
                }
            }
            if (xfound || yfound) break;
            bfs[0].clear();
            std::swap(bfs[0], bfs[1]);
        }
        return (xfound && yfound && (xparent != yparent));
    }
};
