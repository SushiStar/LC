/*
 * You are given a binary tree in which each node contains an integer
 * value. Find out the number of paths that sum to a given value.
 * The path does not need to start or end at the root or leaf, but
 * it must go downwards (traveling only from parent nodes to child nodes).
 * The tree has no more than 1,000 nodes, and the values are in the range
 * -1,000,000 to 1,000,000.
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: Apr/21/2019
 * Author: Wei Du
 */

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int num(0);
        std::vector<int> res;
        subSum(res, root, sum, num);
        return num;
    }

    void subSum(std::vector<int>& res, TreeNode* root, const int& tgt,
                int& num) {
        res.clear();
        if (!root) return;
        std::vector<int> r;
        subSum(res, root->left, tgt, num);
        subSum(r, root->right, tgt, num);
        res.insert(res.end(), r.begin(), r.end());
        res.push_back(0);
        for (auto& subsum : res) {
            subsum += root->val;
            if (subsum == tgt) ++num;
        }
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        auto a = pathSum(root->left, sum);
        auto b = pathSum(root->right, sum);
        return subSum(root,sum) + a + b;
    }

    int subSum(TreeNode* root, int tgt){
        if (!root) return 0;
        int newtgt(tgt-root->val);
        return (tgt==0) + subSum(root->left, newtgt) + subSum(root->right, newtgt);
    }
}
