/*
 * Given two binary trees, write a function to check if they are the same or
 * not. Two binary trees are considered the same if they are structurally
 * identical and the nodes have the same value.
 *
 * Author: Wei Du
 * Date: May/27/2019
 */
#include <queue>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((bool)p ^ (bool)q) { return false; }
        if (!p && !q) { return true; }
        std::queue<TreeNode*> pp;
        std::queue<TreeNode*> qq;
        pp.push(p);
        qq.push(q);
        
        // do bfs for q and p
        while(!pp.empty() && !qq.empty() && pp.size() == qq.size() ) {
            if (pp.front()->val == qq.front()->val) {
                if (pp.front()->left && qq.front()->left) {
                    pp.push(pp.front()->left);
                } else if (pp.front()->left || qq.front()->left) {
                    return false;
                }
                if (pp.front()->right && qq.front()->right) {
                    qq.push(qq.front()->right);
                    pp.push(pp.front()->right);
                } else if (pp.front()->right || qq.front()->right) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return pp.empty()&&qq.empty();
    }
};
