/*
 * Given inorder and postorder traversal of a tree, construct the
 * binary tree.
 *
 * Date: 04/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return nullptr;
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1);
    }

private:
    std::unordered_map<int, int> mp;
    TreeNode *buildTree(const vector<int> &inorder, int il, int ir,
                        const vector<int> &postorder, int pl, int pr) {
        if (pl > pr) return nullptr;
        TreeNode *root = new TreeNode(postorder[pr]);
        int inorder_root_idx = mp[root->val];
        if (inorder_root_idx == ir) {
            root->left = buildTree(inorder, il, ir - 1, postorder, pl, pr - 1);
        } else if (inorder_root_idx == il) {
            root->right = buildTree(inorder, il + 1, ir, postorder, pl, pr - 1);
        } else {
            int rest_right = ir - inorder_root_idx;
            root->left = buildTree(inorder, il, inorder_root_idx - 1, postorder,
                                   pl, pr - 1 - rest_right);
            root->right = buildTree(inorder, inorder_root_idx + 1, ir,
                                    postorder, pr - rest_right, pr - 1);
        }
        return root;
    }
};
