/*
 * Return any binary tree that matches the given preorder and post order
 * traversals. Values in traversals pre and post are distinct positive integers.
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length
 * It is guarangeed an answer exists. If there exists multiple answers, you can
 * return any of them. Date: 06/01/2020 Author: Wei Du
 */
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
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        if (pre.size() <= 1)
            return pre.empty() ? nullptr : (new TreeNode(pre[0]));
        std::vector<int> post_position(post.size()+1);
        for (int i = 0; i < post.size(); ++i) {
            post_position[post[i]] = i;
        }
        return constructTree(pre,0, post.size()-1, post_position);
    }

private:
    TreeNode* constructTree(const vector<int> & pre, int left, int right, const vector<int> &post_position) {
        if (left > right) return nullptr;
        TreeNode* root = new TreeNode(pre[left]);
        if (left == right) return root;

        int length2 = post_position[pre[left]]-post_position[pre[left+1]]-1;
        int length1 = right-left-length2;
        root->left = constructTree(pre, left+1, left+length1, post_position);
        root->right = constructTree(pre, left+length1+1, right, post_position);
        return root;
    }
};
